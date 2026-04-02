#include "hal/gpio.h"

/* STM32 HAL GPIO implementation — Nucleo-F446RE
 *
 * Uncomment when cross-compiling with STM32CubeF4:
 * #include "stm32f4xx_hal.h"
 *
 * Pin mapping: HAL pin numbers are treated as GPIO pin indices (0-15).
 * The actual GPIO port (GPIOA, GPIOB, …) must be resolved by the application.
 * For board-level blinker: LED2 = PA5 on Nucleo-F446RE.
 */

void hal_gpio_init(uint8_t pin, hal_gpio_mode_t mode) {
    /* GPIO_InitTypeDef cfg = {0};
     * cfg.Pin   = (1U << (pin & 0x0F));
     * cfg.Speed = GPIO_SPEED_FREQ_LOW;
     * switch (mode) {
     *     case HAL_GPIO_MODE_OUTPUT:
     *         cfg.Mode = GPIO_MODE_OUTPUT_PP;
     *         cfg.Pull = GPIO_NOPULL;
     *         break;
     *     case HAL_GPIO_MODE_INPUT:
     *         cfg.Mode = GPIO_MODE_INPUT;
     *         cfg.Pull = GPIO_NOPULL;
     *         break;
     *     case HAL_GPIO_MODE_INPUT_PULLUP:
     *         cfg.Mode = GPIO_MODE_INPUT;
     *         cfg.Pull = GPIO_PULLUP;
     *         break;
     *     case HAL_GPIO_MODE_INPUT_PULLDOWN:
     *         cfg.Mode = GPIO_MODE_INPUT;
     *         cfg.Pull = GPIO_PULLDOWN;
     *         break;
     * }
     * HAL_GPIO_Init(GPIOA, &cfg);   // port resolved at board level
     */
    (void)pin; (void)mode;
}

void hal_gpio_write(uint8_t pin, hal_gpio_level_t level) {
    /* HAL_GPIO_WritePin(GPIOA, (1U << (pin & 0x0F)),
     *                   (level == HAL_GPIO_HIGH) ? GPIO_PIN_SET : GPIO_PIN_RESET); */
    (void)pin; (void)level;
}

hal_gpio_level_t hal_gpio_read(uint8_t pin) {
    /* GPIO_PinState s = HAL_GPIO_ReadPin(GPIOA, (1U << (pin & 0x0F)));
     * return (s == GPIO_PIN_SET) ? HAL_GPIO_HIGH : HAL_GPIO_LOW; */
    (void)pin;
    return HAL_GPIO_LOW;
}

void hal_gpio_toggle(uint8_t pin) {
    /* HAL_GPIO_TogglePin(GPIOA, (1U << (pin & 0x0F))); */
    (void)pin;
}
