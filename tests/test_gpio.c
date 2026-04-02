#include "unity.h"
#include "hal/gpio.h"
#include "native_test_helpers.h"

void setUp(void) {}
void tearDown(void) {}

void test_gpio_init_sets_mode(void) {
    hal_gpio_init(5, HAL_GPIO_MODE_OUTPUT);
    TEST_ASSERT_EQUAL(HAL_GPIO_MODE_OUTPUT, native_gpio_get_mode(5));
}
void test_gpio_write_read(void) {
    hal_gpio_init(5, HAL_GPIO_MODE_OUTPUT);
    hal_gpio_write(5, HAL_GPIO_HIGH);
    TEST_ASSERT_EQUAL(HAL_GPIO_HIGH, hal_gpio_read(5));
}
void test_gpio_write_low(void) {
    hal_gpio_init(5, HAL_GPIO_MODE_OUTPUT);
    hal_gpio_write(5, HAL_GPIO_HIGH);
    hal_gpio_write(5, HAL_GPIO_LOW);
    TEST_ASSERT_EQUAL(HAL_GPIO_LOW, hal_gpio_read(5));
}
void test_gpio_toggle(void) {
    hal_gpio_init(5, HAL_GPIO_MODE_OUTPUT);
    hal_gpio_write(5, HAL_GPIO_LOW);
    hal_gpio_toggle(5);
    TEST_ASSERT_EQUAL(HAL_GPIO_HIGH, hal_gpio_read(5));
    hal_gpio_toggle(5);
    TEST_ASSERT_EQUAL(HAL_GPIO_LOW, hal_gpio_read(5));
}
void test_gpio_input_simulation(void) {
    hal_gpio_init(10, HAL_GPIO_MODE_INPUT);
    native_gpio_set_input(10, HAL_GPIO_HIGH);
    TEST_ASSERT_EQUAL(HAL_GPIO_HIGH, hal_gpio_read(10));
}
void test_gpio_init_resets_state(void) {
    hal_gpio_init(5, HAL_GPIO_MODE_OUTPUT);
    hal_gpio_write(5, HAL_GPIO_HIGH);
    hal_gpio_init(5, HAL_GPIO_MODE_OUTPUT);
    TEST_ASSERT_EQUAL(HAL_GPIO_LOW, hal_gpio_read(5));
}
void test_gpio_multiple_pins(void) {
    hal_gpio_init(1, HAL_GPIO_MODE_OUTPUT);
    hal_gpio_init(2, HAL_GPIO_MODE_OUTPUT);
    hal_gpio_write(1, HAL_GPIO_HIGH);
    hal_gpio_write(2, HAL_GPIO_LOW);
    TEST_ASSERT_EQUAL(HAL_GPIO_HIGH, hal_gpio_read(1));
    TEST_ASSERT_EQUAL(HAL_GPIO_LOW, hal_gpio_read(2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_gpio_init_sets_mode);
    RUN_TEST(test_gpio_write_read);
    RUN_TEST(test_gpio_write_low);
    RUN_TEST(test_gpio_toggle);
    RUN_TEST(test_gpio_input_simulation);
    RUN_TEST(test_gpio_init_resets_state);
    RUN_TEST(test_gpio_multiple_pins);
    return UNITY_END();
}
