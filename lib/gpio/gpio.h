#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>

class Gpio {
public:
    enum class Mode : uint8_t { OUT, PWM, DAC, IN };
    Gpio(uint8_t pinId, Mode mode);
    ~Gpio();
    void output(bool value);
    void outputPwm(uint16_t value);  // Arduino: 0~255, ESP32: 0~256
    void outputAnalog(uint8_t value);
    bool input() const;
    uint16_t inputAnalog() const;  // Arduino: 0~1023, ESP32: 0~4095
private:
    uint8_t pinId;
    Mode mode;
#ifdef ESP32
    static const uint8_t PWM_CHANNEL_COUNT = 16;
    static const uint16_t PWM_FREQUENCY = 1000;
    static const uint8_t PWM_RESOLUTION = 8;
    static bool isPwmChannelUsed[PWM_CHANNEL_COUNT];
    uint8_t pwmChannel;
#else
    uint8_t timerId;
#endif
};

#endif
