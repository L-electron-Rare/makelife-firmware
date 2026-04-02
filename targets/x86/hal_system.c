#include "hal/system.h"
#include <time.h>
#include <stdio.h>
static struct timespec start_time;
static int initialized = 0;
void hal_system_init(void) { clock_gettime(CLOCK_MONOTONIC, &start_time); initialized = 1; }
void hal_delay_ms(uint32_t ms) { struct timespec ts = {.tv_sec = ms / 1000, .tv_nsec = (ms % 1000) * 1000000L}; nanosleep(&ts, NULL); }
uint32_t hal_millis(void) { if (!initialized) hal_system_init(); struct timespec now; clock_gettime(CLOCK_MONOTONIC, &now); return (uint32_t)((now.tv_sec - start_time.tv_sec) * 1000 + (now.tv_nsec - start_time.tv_nsec) / 1000000); }
void hal_system_reset(void) { printf("[x86] reset\n"); }
