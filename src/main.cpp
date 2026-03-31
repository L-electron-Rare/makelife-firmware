/**
 * MakeLife Firmware — ESP32 base firmware
 * FineFab ecosystem
 */

#include <Arduino.h>

// Pin definitions
#define LED_BUILTIN 2

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.println("MakeLife Firmware v0.1.0");
    Serial.println("FineFab ecosystem — ESP32");
}

void loop() {
    // Heartbeat LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    Serial.println("heartbeat");
}
