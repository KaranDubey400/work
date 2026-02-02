#include "telemetry.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

typedef struct {
    uint64_t event_id;
    uint32_t sensor_id;
    uint64_t timestamp_ns;
    double   value;
    uint8_t  severity;
} __attribute__((packed)) EventRecord;

static SharedMem *shm;

static int alloc_node() {
    pthread_mutex_lock(&shm->alloc);
    int idx = shm->hdr.free_head;
    if (idx != -1)
        shm->hdr.free_head = shm->nodes[idx].next_idx;
    pthread_mutex_unlock(&shm->alloc);
    return idx;
}

static void free_node(int idx) {
    pthread_mutex_lock(&shm->alloc);
    shm->nodes[idx].next_idx = shm->hdr.free_head;
    shm->hdr.free_head = idx;
    pthread_mutex_unlock(&shm->alloc);
}

static void init_shm() {
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(SharedMem));

    shm = mmap(NULL, sizeof(*shm),
               PROT_READ | PROT_WRITE,
               MAP_SHARED, fd, 0);

    pthread_rwlockattr_t rw;
    pthread_mutexattr_t m;
    pthread_rwlockattr_init(&rw);
    pthread_rwlockattr_setpshared(&rw, PTHREAD_PROCESS_SHARED);
    pthread_mutexattr_init(&m);
    pthread_mutexattr_setpshared(&m, PTHREAD_PROCESS_SHARED);

    pthread_rwlock_init(&shm->rwlock, &rw);
    pthread_mutex_init(&shm->alloc, &m);

    shm->hdr.head_idx = shm->hdr.tail_idx = -1;
    shm->hdr.count = 0;
    shm->hdr.shutdown = 0;

    shm->hdr.free_head = 0;
    for (int i = 0; i < MAX_NODES - 1; i++)
        shm->nodes[i].next_idx = i + 1;
    shm->nodes[MAX_NODES - 1].next_idx = -1;

    memset(&shm->stats, 0, sizeof(shm->stats));
}

int main() {
    init_shm();

    int fd = open("telemetry.bin", O_RDONLY);
    lseek(fd, 0, SEEK_END);

    EventRecord r;
    ssize_t n;

    while (!shm->hdr.shutdown) {
        n = read(fd, &r, sizeof(r));
        if (n < (ssize_t)sizeof(r)) {
            usleep(10000);
            continue;
        }

        pthread_rwlock_wrlock(&shm->rwlock);

        int idx = alloc_node();
        if (idx != -1) {
            EventNode *e = &shm->nodes[idx];
              *e = (EventNode){
                .event_id = r.event_id,
                .sensor_id = r.sensor_id,
                .timestamp_ns = r.timestamp_ns,
                .value = r.value,
                .severity = r.severity,
                .next_idx = -1
            };

            if (shm->hdr.tail_idx != -1)
                shm->nodes[shm->hdr.tail_idx].next_idx = idx;
            else
                shm->hdr.head_idx = idx;

            shm->hdr.tail_idx = idx;
            shm->hdr.count++;

            if (shm->hdr.count > MAX_EVENTS) {
                int old = shm->hdr.head_idx;
                shm->hdr.head_idx = shm->nodes[old].next_idx;
                shm->hdr.count--;
                free_node(old);
            }

            TelemetryStats *s = &shm->stats;
            s->total_events++;
            int si = r.sensor_id - 1;

            if (s->sensor[si].count == 0) {
                s->sensor[si].min = s->sensor[si].max = r.value;
            } else {
                if (r.value < s->sensor[si].min) s->sensor[si].min = r.value;
                if (r.value > s->sensor[si].max) s->sensor[si].max = r.value;
            }

            s->sensor[si].count++;
            s->sensor[si].sum += r.value;
            if (r.severity > s->sensor[si].max_severity)
                s->sensor[si].max_severity = r.severity;

            if (r.severity > s->overall_max_severity)
                s->overall_max_severity = r.severity;

            s->last_event_id = r.event_id;
            s->last_timestamp = r.timestamp_ns;
        }

        pthread_rwlock_unlock(&shm->rwlock);
    }
}
