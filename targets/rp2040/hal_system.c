#include "hal/system.h"

/* Pico SDK System implementation — Raspberry Pi Pico (RP2040)
 *
 * Uncomment when cross-compiling with Pico SDK:
 * #include "pico/stdlib.h"
 * #include "pico/time.h"
 * #include "hardware/watchdog.h"
 *
 * pico_stdlib must be linked (see CMakeLists.txt).
 * stdio_init_all() should be called from app main() for UART/USB output.
 */

void hal_system_init(void) {
    /* stdio_init_all();   // enables UART or USB CDC depending on SDK config */
}

void hal_delay_ms(uint32_t ms) {
    /* sleep_ms(ms); */
    (void)ms;
}

uint32_t hal_millis(void) {
    /* return (uint32_t)(to_ms_since_boot(get_absolute_time())); */
    return 0;
}

void hal_system_reset(void) {
    /* watchdog_reboot(0, 0, 0);   // immediate reboot via watchdog */
}
