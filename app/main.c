#include "hal/gpio.h"
#include "hal/system.h"
#include <stdio.h>

#define LED_PIN 2

int main(void) {
    hal_system_init();
    hal_gpio_init(LED_PIN, HAL_GPIO_MODE_OUTPUT);
    printf("MakeLife Firmware v0.2.0\n");
    printf("FineFab ecosystem — HAL multi-arch\n");
    fflush(stdout);
    for (;;) {
        hal_gpio_toggle(LED_PIN);
        hal_delay_ms(500);
        printf("heartbeat t=%lu ms\n", (unsigned long)hal_millis());
        fflush(stdout);
    }
    return 0;
}
