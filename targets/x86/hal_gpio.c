#include "hal/gpio.h"
static hal_gpio_level_t pin_state[256] = {0};
static hal_gpio_mode_t pin_mode[256] = {0};
void hal_gpio_init(uint8_t pin, hal_gpio_mode_t mode) { pin_mode[pin] = mode; pin_state[pin] = HAL_GPIO_LOW; }
void hal_gpio_write(uint8_t pin, hal_gpio_level_t level) { pin_state[pin] = level; }
hal_gpio_level_t hal_gpio_read(uint8_t pin) { return pin_state[pin]; }
void hal_gpio_toggle(uint8_t pin) { pin_state[pin] = (pin_state[pin] == HAL_GPIO_HIGH) ? HAL_GPIO_LOW : HAL_GPIO_HIGH; }
