#include "hal/system.h"

/* STM32 HAL System implementation — Nucleo-F446RE
 *
 * Uncomment when cross-compiling with STM32CubeF4:
 * #include "stm32f4xx_hal.h"
 *
 * HAL_Init() + SystemClock_Config() must be called from app_main / main()
 * before hal_system_init() when running on hardware.
 */

void hal_system_init(void) {
    /* HAL_Init() is called before main() via startup code.
     * SystemClock_Config() is board-specific — call from application entry.
     * Nothing extra needed here once those are in place. */
}

void hal_delay_ms(uint32_t ms) {
    /* HAL_Delay(ms); */
    (void)ms;
}

uint32_t hal_millis(void) {
    /* return HAL_GetTick();   // SysTick-based ms counter, starts at 0 after HAL_Init() */
    return 0;
}

void hal_system_reset(void) {
    /* HAL_NVIC_SystemReset(); */
}
