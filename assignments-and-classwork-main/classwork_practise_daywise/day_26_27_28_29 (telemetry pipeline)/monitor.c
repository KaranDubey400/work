#include "telemetry.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    int fd;
    SharedMem *shm;

    while (
        (fd = shm_open(SHM_NAME, O_RDWR, 0666)) < 0)
        sleep(1);

    shm = mmap(NULL, sizeof(*shm),
               PROT_READ | PROT_WRITE,
               MAP_SHARED, fd, 0);

    while (!shm->hdr.shutdown) {
        pthread_rwlock_rdlock(&shm->rwlock);

        printf("\nTotal events: %lu\n", shm->stats.total_events);
        printf("Global max Severity: %d\n", shm->stats.overall_max_severity);
        printf("Last event id: %lu\n", shm->stats.last_event_id);
        printf("Current List Size: %d\n", shm->hdr.count);

        // Find Top 5 Sensors
        struct { int id; uint64_t count; } top[5];
        for(int k=0; k<5; k++) { top[k].id = -1; top[k].count = 0; }

        for (int i = 0; i < MAX_SENSORS; i++) {
            uint64_t c = shm->stats.sensor[i].count;
            if (c == 0) continue;

            for(int k=0; k<5; k++) {
                if (c > top[k].count) {
                   
                    for(int m=4; m>k; m--) {
                        top[m] = top[m-1];
                    }
                    top[k].id = i;
                    top[k].count = c;
                    break;
                }
            }
        }

        printf("Top 5 Sensors:\n");
        for(int k=0; k<5; k++) {
            if (top[k].id != -1) {
                int i = top[k].id;
                double avg = (shm->stats.sensor[i].count > 0) ? 
                             (shm->stats.sensor[i].sum / shm->stats.sensor[i].count) : 0.0;
                printf("  Sensor %d: count=%lu avg=%.2f\n", i + 1, shm->stats.sensor[i].count, avg);
            }
        }

        pthread_rwlock_unlock(&shm->rwlock);
        usleep(500000);
    }
}
