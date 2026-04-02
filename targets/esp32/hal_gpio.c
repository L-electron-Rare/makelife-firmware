#include "hal/gpio.h"
void hal_gpio_init(uint8_t pin, hal_gpio_mode_t mode) { (void)pin; (void)mode; }
void hal_gpio_write(uint8_t pin, hal_gpio_level_t level) { (void)pin; (void)level; }
hal_gpio_level_t hal_gpio_read(uint8_t pin) { (void)pin; return HAL_GPIO_LOW; }
void hal_gpio_toggle(uint8_t pin) { (void)pin; }
