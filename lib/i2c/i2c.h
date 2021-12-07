#ifndef _I2C_H_
#define _I2C_H_

#include <stdint.h>

class I2c {
public:
    I2c();
#ifdef ESP32
    I2c(uint8_t sdaPinId, uint8_t sclPinId);
#endif
    bool write(uint8_t address, uint8_t reg);
    bool write(uint8_t address, uint8_t reg, uint8_t data);
    bool read(uint8_t address, uint8_t reg, uint8_t* data, uint8_t length = 1);
};

#endif
