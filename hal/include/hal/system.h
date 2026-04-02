#pragma once
#include <stdint.h>

void hal_system_init(void);
void hal_delay_ms(uint32_t ms);
uint32_t hal_millis(void);
void hal_system_reset(void);
