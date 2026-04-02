#pragma once
#include "hal/gpio.h"
void native_gpio_set_input(uint8_t pin, hal_gpio_level_t level);
hal_gpio_mode_t native_gpio_get_mode(uint8_t pin);
