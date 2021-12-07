#ifndef _SERVOMOTOR_H_
#define _SERVOMOTOR_H_

#ifdef ESP32
#include <ESP32Servo.h>
#else
#include <Servo.h>
#endif

class ServoMotor {
public:
    enum class Model : uint8_t { SG90, FT90B, ES08A };
    ServoMotor(uint8_t pinId, Model model = Model::SG90);
    void angle(uint8_t angle);
    uint8_t angle();
private:
    Servo servo;
};

#endif
