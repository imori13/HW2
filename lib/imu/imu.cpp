#include <imu.h>

Imu::Imu(I2c* i2c) {
    this->i2c = i2c;
}

bool Imu::init() {
    return (this->i2c->write(this->ADDRESS, this->REG_CONFIG, this->VAL_CONFIG__GYRO_176HZ) &&
        this->i2c->write(this->ADDRESS, this->REG_GYRO_CONFIG, this->VAL_GYRO_CONFIG__2KDPS) &&
        this->i2c->write(this->ADDRESS, this->REG_ACCEL_CONFIG, this->VAL_ACCEL_CONFIG__16G) &&
        this->i2c->write(this->ADDRESS, this->REG_ACCEL_CONFIG2, this->VAL_ACCEL_CONFIG2__420HZ) &&
        this->i2c->write(this->ADDRESS, this->REG_PWR_MGMT_1, this->VAL_PWR_MGMT_1__LOW_NOISE));
}

bool Imu::getAccelG(Vector3* vector) {
    return this->getVector(vector, this->REG_ACCEL_XOUT_H, this->ACCEL_SENSITIVITY_16G);
}

bool Imu::getGyroDps(Vector3* vector) {
    return this->getVector(vector, this->REG_GYRO_XOUT_H, this->GYRO_SENSITIVITY_2KDPS);
}

bool Imu::getTemperature(float* value) {
    uint8_t data[2];
    if (!this->i2c->read(this->ADDRESS, this->REG_TEMP_OUT_H, data, sizeof(data))) return false;
    *value = ((float)(int16_t)(((uint16_t)data[0] << 8) + data[1]) / this->TEMP_SENSITIVITY +
        this->TEMP_OFFSET);
    return true;
}

bool Imu::getVector(Vector3* vector, uint8_t reg, float sensitivity) {
    uint8_t data[6];
    if (!this->i2c->read(this->ADDRESS, reg, data, sizeof(data))) return false;
    vector->x = (float)(int16_t)(((uint16_t)data[0] << 8) + data[1]) / sensitivity;
    vector->y = (float)(int16_t)(((uint16_t)data[2] << 8) + data[3]) / sensitivity;
    vector->z = (float)(int16_t)(((uint16_t)data[4] << 8) + data[5]) / sensitivity;
    return true;
}
