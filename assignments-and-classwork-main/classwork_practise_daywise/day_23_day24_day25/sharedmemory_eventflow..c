#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SHM_NAME "/event_shm"
#define MAX_NODES 4096
#define MAX_EVENTS 2000
#define THRESH_T  10

typedef struct {
    int event_id;
    int sensor_id;
    long timestamp;
    double value;
    int severity;
    int next_idx;   
} EventNode;

typedef struct {
    int head_idx;
    int tail_idx;
    int count;
    unsigned long version;
    int shutdown;
} ListHeader;

typedef struct {
    pthread_rwlock_t list_lock;
    pthread_mutex_t lock;

    ListHeader hdr;
    EventNode pool[MAX_NODES];
    int free_head;
} Sharedmem;

Sharedmem *shm;
int pop_free(){
  int idx = shm->free_head;
    if(idx != -1){
      shm->free_head = shm->pool[idx].next_idx;
    }
      return idx;
      }
void push_free(int idx) {
    shm->pool[idx].next_idx = shm->free_head;
    shm->free_head = idx;
}

//Writer Thread
void* writer_thread(void *arg){
while (!shm->hdr.shutdown) {
    pthread_rwlock_wrlock(&shm->list_lock);
    pthread_mutex_lock(&shm->lock);
    int idx = pop_free();
    pthread_mutex_unlock(&shm->lock);
    
    if (idx != -1) {
        EventNode *n = &shm->pool[idx];
        n->event_id = rand() % 1000;
        n->sensor_id = rand() % 10;
        n->timestamp = time(NULL);
        n->severity = rand() % 5;
        n->value = (double)(rand() % 100);
        n->next_idx = -1;
        
        
        if (shm->hdr.head_idx == -1){
            shm->hdr.head_idx = idx;
            }
        else {
            shm->pool[shm->hdr.tail_idx].next_idx = idx;
            }
            
            shm->hdr.tail_idx = idx;
            shm->hdr.count++;
            shm->hdr.version++;
          
             if (shm->hdr.count > MAX_EVENTS) {
                int old = shm->hdr.head_idx;
                shm->hdr.head_idx = shm->pool[old].next_idx;
                if (shm->hdr.head_idx == -1)
                    shm->hdr.tail_idx = -1;
                shm->hdr.count--;
                shm->hdr.version++;

                pthread_mutex_lock(&shm->lock);
                push_free(old);
                pthread_mutex_unlock(&shm->lock);
            }
           
        }

        pthread_rwlock_unlock(&shm->list_lock);
        usleep(100000);
    }
    return NULL;
}

// Updater Thread 

void* updater_thread(void *arg) {
    while (!shm->hdr.shutdown) {
        pthread_rwlock_wrlock(&shm->list_lock);

        if (shm->hdr.count > 0) {
            int steps = rand() % shm->hdr.count;
            int cur = shm->hdr.head_idx;
            while (steps-- && cur != -1)
                cur = shm->pool[cur].next_idx;

            if (cur != -1) {
                shm->pool[cur].severity = rand() % 10;
                shm->hdr.version++;
            }
        }

        pthread_rwlock_unlock(&shm->list_lock);
        sleep(1);
    }
    return NULL;
}

// Cleaner Thread 
void* cleaner_thread(void *arg){
      while (!shm->hdr.shutdown) {
      pthread_rwlock_wrlock(&shm->list_lock);
       long now = time(NULL);
       while (shm->hdr.head_idx != -1 && shm->pool[shm->hdr.head_idx].timestamp < (now - THRESH_T)) {
            int old = shm->hdr.head_idx;
            shm->hdr.head_idx = shm->pool[old].next_idx;
            if (shm->hdr.head_idx == -1)
                shm->hdr.tail_idx = -1;

            shm->hdr.count--;
            shm->hdr.version++;

            pthread_mutex_lock(&shm->lock);
            push_free(old);
            pthread_mutex_unlock(&shm->lock);
        }

        pthread_rwlock_unlock(&shm->list_lock);
        sleep(2);
    }
    return NULL;
}

// Snapshot Thread 

void* snapshot_thread(void *arg) {
    while (!shm->hdr.shutdown) {
        pthread_rwlock_rdlock(&shm->list_lock);

        int c = 0;
        double sum = 0, max = 0;
        int cur = shm->hdr.head_idx;

        while(cur != -1) {
        sum += shm->pool[cur].value;
        if (shm->pool[cur].value > max)
            max = shm->pool[cur].value;
            
            c++;
            cur = shm->pool[cur].next_idx;
        }

        pthread_rwlock_unlock(&shm->list_lock);
        if (c)
            printf("Snapshot c = %d avg = %.2f max = %.2f \n" ,c,sum/c,max);
            sleep(2);
        }
        return NULL;
  }

//Query Thread

void* query_thread(void* arg){
  while(!shm->hdr.shutdown){
    pthread_rwlock_rdlock(&shm->list_lock);
    
    int cur = shm->hdr.head_idx;
    int count = 0;
    while(cur != -1){
      if (shm->pool[cur].severity >= 10)
        count ++;
      cur = shm->pool[cur].next_idx;
      }
    
    pthread_rwlock_unlock(&shm->list_lock);
      printf("[Query] severity >= 10 : %d \n" , count);
      sleep(3);
      }
      return NULL;
      }

// Watchdog Thread

void* watchdog_thread(void *arg) {
    unsigned long last = shm->hdr.version;

    while (!shm->hdr.shutdown) {
        sleep(4);
        if (shm->hdr.version == last)
            printf("Warning: no update detected\n");
        last = shm->hdr.version;
    }
    return NULL;
}

// Shared Memory

void in_shared(int create){
    int f = shm_open(SHM_NAME , O_CREAT | O_RDWR , 0666);
    if(f<0) {
    perror("shm_open");
    exit(1);
    }
    ftruncate(f , sizeof(Sharedmem));
    
    
   shm = mmap(NULL, sizeof(Sharedmem),  PROT_READ | PROT_WRITE,  MAP_SHARED, f, 0);

    if (shm == MAP_FAILED) { perror("mmap"); exit(1); }
    
    if (create) {
        pthread_rwlockattr_t rw;
        pthread_mutexattr_t m;
        pthread_rwlockattr_init(&rw);
        pthread_rwlockattr_setpshared(&rw, PTHREAD_PROCESS_SHARED);
        pthread_mutexattr_init(&m);
        pthread_mutexattr_setpshared(&m , PTHREAD_PROCESS_SHARED);
        
        pthread_rwlock_init(&shm->list_lock,&rw);
        pthread_mutex_init(&shm->lock, &m);
        
        shm->hdr.head_idx = -1;
        shm->hdr.tail_idx = -1;
        shm->hdr.count = 0;
        shm->hdr.version = 0;
        shm->hdr.shutdown = 0;
        
        shm->free_head = 0;
        for(int i=0;i < MAX_NODES - 1; i++){
            shm->pool[i].next_idx = i + 1;
           }
            shm->pool[MAX_NODES - 1].next_idx = -1;
            }
            }
            
    // Main 
    int main (int argc , char *argv[]) {
    srand(time(NULL));
    
    if (argc < 2) {
        printf("Use: %s producer|consumer \n",argv[0]);
        return 0;
        }
    
    if (!strcmp(argv[1], "producer")){
        in_shared(1);
        
        pthread_t w1 , w2 , upd , clr;
        pthread_create(&w1, NULL,writer_thread,NULL);
        pthread_create(&w2, NULL,writer_thread,NULL);
        pthread_create(&upd ,NULL,updater_thread,NULL);      
        pthread_create(&clr ,NULL,cleaner_thread,NULL);
        
        sleep(30);
        shm->hdr.shutdown = 1;
        
        pthread_join(w1,NULL);
        pthread_join(w2,NULL);
        pthread_join(upd,NULL);
        pthread_join(clr,NULL);
        
        munmap(shm, sizeof(Sharedmem));
        shm_unlink(SHM_NAME);
        }
        
        else {
        in_shared(0);
        
        pthread_t s1, s2 , q , wd;
        pthread_create(&s1, NULL,snapshot_thread,NULL);
        pthread_create(&s2, NULL,snapshot_thread,NULL);
        pthread_create(&q ,NULL,query_thread,NULL);      
        pthread_create(&wd ,NULL,watchdog_thread,NULL);
        
        while(!shm->hdr.shutdown){
              sleep(1);
              }
        pthread_join(s1,NULL);
        pthread_join(s2,NULL);
        pthread_join(q,NULL);
        pthread_join(wd,NULL);
        munmap(shm, sizeof(Sharedmem));
        
        }
        }