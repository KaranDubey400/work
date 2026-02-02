#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


typedef struct node {
    char* key;          
    char* value;       
    struct node* prev;
    struct node* next;
} node;



typedef struct {
    int capacity;       
    int currentsize; 
    node* head;         
    node* tail;        
    pthread_mutex_t lock; 
} lru_cache;




char* read(const char* filename) {


    FILE* file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    
    fseek(file, 0, SEEK_END);


    long length = ftell(file);

    fseek(file, 0, SEEK_SET);


    char* content = (char*)malloc(length + 1);

    if (content) {
        fread(content, 1, length, file);
        content[length] = '\0';
    }

    fclose(file);

    return content;
}


lru_cache* create_cache(int capacity) {
    
    lru_cache* cache = ( lru_cache*)malloc(sizeof(lru_cache));
    cache->capacity = capacity;
    cache->current_size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    pthread_mutex_init(&cache->lock, NULL);
    return cache;
}


void addToHead( lru_cache* cache, Node* node) {
    node->next = cache->head;
    node->prev = NULL;
    
    
    if (cache->head != NULL) {
        cache->head->prev = node;
    }
    
    cache->head = node;
    
    if (cache->tail == NULL) {
        cache->tail = node;
    }
}


void removeNode( lru_cache* cache, Node* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev; 
    }
}


void moveToHead( lru_cache* cache, Node* node) {
    removeNode(cache, node);
    addToHead(cache, node);
}


char* get( lru_cache* cache, char* key) {
  
    pthread_mutex_lock(&cache->lock);

   
    Node* current = cache->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
          
            printf("[hit] Key: %s found in cache.\n", key);
            moveToHead(cache, current);
            
         
            char* result = strdup(current->value);
            
            pthread_mutex_unlock(&cache->lock);
            return result;
        }
        current = current->next;
    }

   
    printf("[miss] Key: %s not in cache. loading from disk.\n", key);

    char* content = readFile(key);
    
    if (content == NULL) {
        printf("[error] file %s not found.\n", key);
        pthread_mutex_unlock(&cache->lock);
        return NULL;
    }

    
    if (cache->current_size >= cache->capacity) {
        Node* lruNode = cache->tail;
        printf("[evict] cache full! Removing oldest key: %s\n", lruNode->key);
        
        removeNode(cache, lruNode);
        
       
        free(lruNode->key);
        free(lruNode->value);
        free(lruNode);
        cache->current_size--;
    }


    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = content;
    
    addToHead(cache, newNode);
    cache->current_size++;

   
    char* result = strdup(content);
    pthread_mutex_unlock(&cache->lock);
    return result;
}



typedef struct {
    int id;
     lru_cache* cache;
    char** files;
    int num_files;
} ThreadArgs;


void* worker(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    
    for (int i = 0; i < args->num_files; i++) {
        

        usleep(rand() % 10000); 
        
        char* fileToRead = args->files[i];
        char* content = get(args->cache, fileToRead);
        
        if (content) {
        
            printf("Thread %d got content for %s\n", args->id, fileToRead);
            free(content); 
        }
    }
    return NULL;
}

int main() {
   
     lru_cache* cache = createCache(3); 

    char* files[] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file1.txt", "file2.txt"};
    int num_files_to_read = 6;

   
    int num_threads = 4;
    pthread_t threads[num_threads];
    ThreadArgs args[num_threads];

    printf("starting %d threads...\n", num_threads);

    for (int i = 0; i < num_threads; i++) {
        args[i].id = i;
        args[i].cache = cache;
        args[i].files = files; 
        args[i].num_files = num_files_to_read;
        
        pthread_create(&threads[i], NULL, worker, &args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }


    
     return 0;
}
