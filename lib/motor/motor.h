#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <i2c.h>

class Motor {
public:
    class Address {
    public:
        static const uint8_t CH1 = 0x65;
        static const uint8_t CH2 = 0x60;
    };
    float maxVoltage = 3;
    Motor(I2c* i2c, uint8_t address);
    bool drive(float voltage);
    bool brake();
private:
    static const uint8_t REG_CONTROL = 0x00;
    static const uint8_t VAL_CONTROL__VSET_MIN = 0x06;
    static const uint8_t VAL_CONTROL__VSET_MAX = 0x3f;
    static const uint8_t VAL_CONTROL__BRIDGE_COAST = 0x00;
    static const uint8_t VAL_CONTROL__BRIDGE_FORWARD = 0x01;
    static const uint8_t VAL_CONTROL__BRIDGE_REVERSE = 0x02;
    static const uint8_t VAL_CONTROL__BRIDGE_BRAKE = 0x03;
    static constexpr float VOLTAGE_PER_LSB = 0.08035;
    I2c* i2c;
    uint8_t address;
};

#endif
