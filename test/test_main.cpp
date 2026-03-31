#include <unity.h>

void test_led_pin_defined(void) {
    TEST_ASSERT_EQUAL(2, LED_BUILTIN);
}

void test_firmware_version(void) {
    TEST_ASSERT_TRUE(true); // Placeholder
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_led_pin_defined);
    RUN_TEST(test_firmware_version);
    return UNITY_END();
}
