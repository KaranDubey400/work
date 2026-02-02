#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <stdint.h>
#include <pthread.h>

#define SHM_NAME "/telemetry_shm"
#define MAX_EVENTS 2000
#define MAX_NODES  4096
#define MAX_SENSORS 64

typedef struct {
    uint64_t event_id;
    uint32_t sensor_id;
    uint64_t timestamp_ns;
    double   value;
    uint8_t  severity;
    int      next_idx;
} EventNode;

typedef struct {
    uint64_t total_events;

    struct {
        uint64_t count;
        double   sum;
        double   min;
        double   max;
        uint8_t  max_severity;
    } sensor[MAX_SENSORS];

    uint8_t overall_max_severity;
    uint64_t last_event_id;
    uint64_t last_timestamp;
} TelemetryStats;

typedef struct {
    int head_idx;
    int tail_idx;
    int count;
    int free_head;
    int shutdown;
} ListHeader;

typedef struct {
    pthread_rwlock_t rwlock;  
    pthread_mutex_t  alloc;  

    ListHeader hdr;
    TelemetryStats stats;
    EventNode nodes[MAX_NODES];
} SharedMem;

#endif
