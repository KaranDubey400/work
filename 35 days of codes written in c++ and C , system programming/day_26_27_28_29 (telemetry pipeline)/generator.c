#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint64_t event_id;
    uint32_t sensor_id;
    uint64_t timestamp_ns;
    double   value;
    uint8_t  severity;
} __attribute__((packed)) EventRecord;

static uint64_t now_ns() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

int main() {
    FILE *f = fopen("telemetry.bin", "ab");
    if (!f) { perror("fopen"); return 1; }

    uint64_t id = 0;
    srand(time(NULL));

    while (1) {
        EventRecord r;
        r.event_id = id++;
        r.sensor_id = (rand() % 64) + 1;
        r.timestamp_ns = now_ns();
        
        r.value = (double)(rand() % 1000) / 10.0;
        r.severity = rand() % 6;

        fwrite(&r, sizeof(r), 1, f);
        fflush(f);               
        usleep(10000);           
    }
    
}
