#include "unity.h"
#include "hal/system.h"

void setUp(void) {}
void tearDown(void) {}

void test_system_init(void) {
    hal_system_init();
    TEST_PASS();
}
void test_millis_increases(void) {
    hal_system_init();
    uint32_t t1 = hal_millis();
    hal_delay_ms(10);
    uint32_t t2 = hal_millis();
    TEST_ASSERT_GREATER_THAN(t1, t2);
}
void test_millis_resolution(void) {
    hal_system_init();
    uint32_t t1 = hal_millis();
    hal_delay_ms(50);
    uint32_t t2 = hal_millis();
    uint32_t elapsed = t2 - t1;
    TEST_ASSERT_GREATER_OR_EQUAL(30, elapsed);
    TEST_ASSERT_LESS_OR_EQUAL(100, elapsed);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_system_init);
    RUN_TEST(test_millis_increases);
    RUN_TEST(test_millis_resolution);
    return UNITY_END();
}
