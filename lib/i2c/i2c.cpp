#include <Arduino.h>
#include <Wire.h>
#include <i2c.h>

I2c::I2c() {
    Wire.begin();
}

#ifdef ESP32
I2c::I2c(uint8_t sdaPinId, uint8_t sclPinId) {
    Wire.begin(sdaPinId, sclPinId);
}
#endif

bool I2c::write(uint8_t address, uint8_t reg) {
    Wire.beginTransmission(address);
    Wire.write(reg);
    return Wire.endTransmission() == 0;
}

bool I2c::write(uint8_t address, uint8_t reg, uint8_t data) {
    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.write(data);
    return Wire.endTransmission() == 0;
}

bool I2c::read(uint8_t address, uint8_t reg, uint8_t* data, uint8_t length) {
    this->write(address, reg);
    const uint8_t received = Wire.requestFrom(address, length);
    for (uint8_t* p = data; p < data + min(received, length); p++) {
        *p = Wire.read();
    }
    while (Wire.available()) {
        Wire.read();
    }
    return received >= length;
}
