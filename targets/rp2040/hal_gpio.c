#include "hal/gpio.h"

/* Pico SDK GPIO implementation — Raspberry Pi Pico (RP2040)
 *
 * Uncomment when cross-compiling with Pico SDK:
 * #include "hardware/gpio.h"
 *
 * The Pico SDK uses a flat pin numbering (GP0–GP28). HAL pin numbers
 * map directly to GP numbers on the Pico.
 */

void hal_gpio_init(uint8_t pin, hal_gpio_mode_t mode) {
    /* gpio_init(pin);
     * switch (mode) {
     *     case HAL_GPIO_MODE_OUTPUT:
     *         gpio_set_dir(pin, GPIO_OUT);
     *         break;
     *     case HAL_GPIO_MODE_INPUT:
     *         gpio_set_dir(pin, GPIO_IN);
     *         gpio_disable_pulls(pin);
     *         break;
     *     case HAL_GPIO_MODE_INPUT_PULLUP:
     *         gpio_set_dir(pin, GPIO_IN);
     *         gpio_pull_up(pin);
     *         break;
     *     case HAL_GPIO_MODE_INPUT_PULLDOWN:
     *         gpio_set_dir(pin, GPIO_IN);
     *         gpio_pull_down(pin);
     *         break;
     * }
     */
    (void)pin; (void)mode;
}

void hal_gpio_write(uint8_t pin, hal_gpio_level_t level) {
    /* gpio_put(pin, (level == HAL_GPIO_HIGH) ? 1 : 0); */
    (void)pin; (void)level;
}

hal_gpio_level_t hal_gpio_read(uint8_t pin) {
    /* return gpio_get(pin) ? HAL_GPIO_HIGH : HAL_GPIO_LOW; */
    (void)pin;
    return HAL_GPIO_LOW;
}

void hal_gpio_toggle(uint8_t pin) {
    /* gpio_xor_mask(1u << pin); */
    (void)pin;
}
