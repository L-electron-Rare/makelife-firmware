#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    HAL_GPIO_MODE_INPUT,
    HAL_GPIO_MODE_OUTPUT,
    HAL_GPIO_MODE_INPUT_PULLUP,
    HAL_GPIO_MODE_INPUT_PULLDOWN,
} hal_gpio_mode_t;

typedef enum {
    HAL_GPIO_LOW = 0,
    HAL_GPIO_HIGH = 1,
} hal_gpio_level_t;

void hal_gpio_init(uint8_t pin, hal_gpio_mode_t mode);
void hal_gpio_write(uint8_t pin, hal_gpio_level_t level);
hal_gpio_level_t hal_gpio_read(uint8_t pin);
void hal_gpio_toggle(uint8_t pin);
