#ifndef _IMU_H_
#define _IMU_H_

#include <i2c.h>
#include <vector3.h>

class Imu {
public:
    Imu(I2c* i2c);
    bool init();
    bool getAccelG(Vector3* vector);
    bool getGyroDps(Vector3* vector);
    bool getTemperature(float* value);
private:
    static const uint8_t ADDRESS = 0x69;
    static const uint8_t REG_CONFIG = 0x1a;
    static const uint8_t REG_GYRO_CONFIG = 0x1b;
    static const uint8_t REG_ACCEL_CONFIG = 0x1c;
    static const uint8_t REG_ACCEL_CONFIG2 = 0x1d;
    static const uint8_t REG_ACCEL_XOUT_H = 0x3b;
    static const uint8_t REG_TEMP_OUT_H = 0x41;
    static const uint8_t REG_GYRO_XOUT_H = 0x43;
    static const uint8_t REG_PWR_MGMT_1 = 0x6b;
    static const uint8_t VAL_CONFIG__GYRO_176HZ = 0x01;
    static const uint8_t VAL_GYRO_CONFIG__2KDPS = 0x18;
    static const uint8_t VAL_ACCEL_CONFIG__16G = 0x18;
    static const uint8_t VAL_ACCEL_CONFIG2__420HZ = 0x07;
    static const uint8_t VAL_PWR_MGMT_1__LOW_NOISE = 0x01;
    static constexpr float ACCEL_SENSITIVITY_16G = 2048;
    static constexpr float GYRO_SENSITIVITY_2KDPS = 16.4;
    static constexpr float TEMP_SENSITIVITY = 326.8;
    static constexpr float TEMP_OFFSET = 25;
    I2c* i2c;
    bool getVector(Vector3* vector, uint8_t reg, float sensitivity);
};

#endif
