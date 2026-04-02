#include "hal/system.h"
void hal_system_init(void) {}
void hal_delay_ms(uint32_t ms) { (void)ms; }
uint32_t hal_millis(void) { return 0; }
void hal_system_reset(void) {}
