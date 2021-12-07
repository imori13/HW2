#include <Arduino.h>
#include <compass.h>

Compass::Compass(I2c* i2c) {
    this->i2c = i2c;
}

bool Compass::init() {
    if (!(this->i2c->write(this->ADDRESS, this->REG_CNTL2, this->VAL_CNTL2__POWER_DOWN) &&
        this->i2c->write(this->ADDRESS, this->REG_CNTL2, this->VAL_CNTL2__100HZ))) return false;
    const uint8_t maxWaitForDataReadyMs = 1000 / 10;
    bool isReady = false;
    for (uint8_t ms = 0; ms < maxWaitForDataReadyMs; ms++) {
        uint8_t value;
        if (!this->i2c->read(this->ADDRESS, this->REG_ST1, &value)) return false;
        isReady = value & BIT_ST1__DRDY;
        if (isReady) break;
        delay(1);
    }
    return isReady;
}

bool Compass::getMagneticField(Vector3* vector) {
    uint8_t data[8];
    if (!this->i2c->read(this->ADDRESS, this->REG_HXL, data, sizeof(data))) return false;
    vector->x = (float)(int16_t)(data[0] + ((uint16_t)data[1] << 8)) * this->SENSITIVITY;
    vector->y = (float)(int16_t)(data[2] + ((uint16_t)data[3] << 8)) * this->SENSITIVITY;
    vector->z = (float)(int16_t)(data[4] + ((uint16_t)data[5] << 8)) * this->SENSITIVITY;
    this->maxEdge = this->maxEdge.maxEdge(*vector);
    this->minEdge = this->minEdge.minEdge(*vector);
    *vector -= (this->maxEdge + this->minEdge) / 2;
    return true;
}
