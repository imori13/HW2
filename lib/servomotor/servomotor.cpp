#include <servomotor.h>

ServoMotor::ServoMotor(uint8_t pinId, Model model) {
    unsigned int minPulseWidth = MIN_PULSE_WIDTH;
    unsigned int maxPulseWidth = MAX_PULSE_WIDTH;
    switch (model) {
        case ServoMotor::Model::SG90:
            minPulseWidth = 600;
            maxPulseWidth = 2350;
            break;
        case ServoMotor::Model::FT90B:
            minPulseWidth = 500;
            maxPulseWidth = 2500;
            break;
        case ServoMotor::Model::ES08A:
            minPulseWidth = 650;
            break;
    }
    this->servo.attach(pinId, minPulseWidth, maxPulseWidth);
}

void ServoMotor::angle(uint8_t angle) {
    this->servo.write(angle);
}

uint8_t ServoMotor::angle() {
    return this->servo.read();
}
