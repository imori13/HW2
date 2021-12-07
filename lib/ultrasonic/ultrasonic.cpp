#include <Arduino.h>
#include <ultrasonic.h>

Ultrasonic::Ultrasonic(uint8_t pinId) {
    this->pinId = pinId;
}

bool Ultrasonic::measureDistanceMm(uint16_t* value) {
    this->requestPulse();
    uint32_t width;
    if (!this->measurePulseWidthUs(&width)) return false;
    *value = width / 5.8;
    return true;
}

void Ultrasonic::requestPulse() {
    pinMode(this->pinId, OUTPUT);
    digitalWrite(this->pinId, LOW);
    delayMicroseconds(2);
    digitalWrite(this->pinId, HIGH);
    delayMicroseconds(5);
    digitalWrite(this->pinId, LOW);
}

bool Ultrasonic::measurePulseWidthUs(uint32_t* width) {
    const uint32_t timeoutUs = 100ul * 1000;
    const uint32_t startedUs = micros();
    pinMode(this->pinId, INPUT);
    while (digitalRead(this->pinId) == HIGH) {
        if (micros() - startedUs > timeoutUs) return false;
    }
    while (digitalRead(this->pinId) == LOW) {
        if (micros() - startedUs > timeoutUs) return false;
    }
    const uint32_t pulseStartedUs = micros();
    while (digitalRead(this->pinId) == HIGH) {
        if (micros() - startedUs > timeoutUs) return false;
    }
    *width = micros() - pulseStartedUs;
    return true;
}
