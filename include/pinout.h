#ifndef _PINOUT_H_
#define _PINOUT_H_

#include <stdint.h>

class Pinout {
public:
#ifdef ESP32
    static const uint8_t ID_CN1 = 25;
    static const uint8_t ID_CN1_2 = 14;
    static const uint8_t ID_CN2 = 26;
    static const uint8_t ID_CN2_2 = 15;
    static const uint8_t ID_CN3 = 4;
    static const uint8_t ID_SDA = 19;
    static const uint8_t ID_SCL = 21;
#else
    static const uint8_t D2 = 2;
    static const uint8_t D3_PWM_READY = 3;
    static const uint8_t D4 = 4;
    static const uint8_t D5_PWM_READY = 5;
    static const uint8_t D6_PWM_READY = 6;
    static const uint8_t D7 = 7;
    static const uint8_t LED = 13;
    static const uint8_t A0 = 14;
    static const uint8_t A1 = 15;
    static const uint8_t A2 = 16;
    static const uint8_t A3 = 17;
    static const uint8_t A6_AIN_ONLY = 20;
    static const uint8_t A7_AIN_ONLY = 21;
#endif
};

#endif
