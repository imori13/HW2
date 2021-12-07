#ifndef _COMPASS_H_
#define _COMPASS_H_

#include <i2c.h>
#include <vector3.h>

class Compass {
public:
    Compass(I2c* i2c);
    bool init();
    bool getMagneticField(Vector3* vector);
private:
    static const uint8_t ADDRESS = 0x0c;
    static const uint8_t REG_ST1 = 0x10;
    static const uint8_t REG_HXL = 0x11;
    static const uint8_t REG_CNTL2 = 0x31;
    static const uint8_t BIT_ST1__DRDY = 0x01;
    static const uint8_t VAL_CNTL2__POWER_DOWN = 0x00;
    static const uint8_t VAL_CNTL2__100HZ = 0x08;
    static constexpr float SENSITIVITY = 0.15;
    I2c* i2c;
    Vector3 maxEdge;
    Vector3 minEdge;
};

#endif
