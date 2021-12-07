#include <Arduino.h>
#include <gpio.h>
#include <timer_util.h>

#ifdef ESP32
bool Gpio::isPwmChannelUsed[Gpio::PWM_CHANNEL_COUNT] = {false};
#endif

Gpio::Gpio(uint8_t pinId, Mode mode) {
    this->pinId = pinId;
    this->mode = mode;
    if (this->mode == Gpio::Mode::OUT) {
        pinMode(this->pinId, OUTPUT);
#ifdef ESP32
    } else if (this->mode == this->Mode::PWM) {
        for (this->pwmChannel = 0; this->pwmChannel < this->PWM_CHANNEL_COUNT; this->pwmChannel++) {
            if (!this->isPwmChannelUsed[this->pwmChannel]) {
                break;
            }
        }
        if (this->pwmChannel < this->PWM_CHANNEL_COUNT) {
            this->isPwmChannelUsed[this->pwmChannel] = true;
            ledcSetup(this->pwmChannel, this->PWM_FREQUENCY, this->PWM_RESOLUTION);
            ledcAttachPin(this->pinId, this->pwmChannel);
        }
#else
    } else if (this->mode == Gpio::Mode::DAC) {
        pinMode(this->pinId, OUTPUT);
        this->timerId = digitalPinToTimer(this->pinId);
        TimerUtil::enableFastPwm(this->timerId, true);
#endif
    } else if (this->mode == Gpio::Mode::IN) {
        pinMode(this->pinId, INPUT);
    }
}

Gpio::~Gpio() {
#ifdef ESP32
    if (this->mode == this->Mode::PWM && this->pwmChannel < this->PWM_CHANNEL_COUNT) {
        ledcDetachPin(this->pinId);
        this->isPwmChannelUsed[this->pwmChannel] = false;
    }
#else
    if (this->mode == Gpio::Mode::DAC) {
        TimerUtil::enableFastPwm(this->timerId, false);
    }
#endif
}

void Gpio::output(bool value) {
    if (this->mode != Gpio::Mode::OUT) return;
    digitalWrite(this->pinId, value ? HIGH : LOW);
}

void Gpio::outputPwm(uint16_t value) {
    if (this->mode != Gpio::Mode::PWM) return;
#ifdef ESP32
    if (this->pwmChannel < this->PWM_CHANNEL_COUNT) {
        ledcWrite(this->pwmChannel, min(value, (uint16_t)256));
    }
#else
    analogWrite(this->pinId, min(value, 255));
#endif
}

void Gpio::outputAnalog(uint8_t value) {
    if (this->mode != Gpio::Mode::DAC) return;
#ifdef ESP32
    dacWrite(this->pinId, value);
#else
    TimerUtil::setComparedValue(this->timerId, value);
#endif
}

bool Gpio::input() const {
    if (this->mode != Gpio::Mode::IN) return false;
    return digitalRead(this->pinId) == HIGH;
}

uint16_t Gpio::inputAnalog() const {
    if (this->mode != Gpio::Mode::IN) return 0;
    return analogRead(this->pinId);
}
