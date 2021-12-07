#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

#include <stdint.h>

class Ultrasonic {
public:
    Ultrasonic(uint8_t pinId);
    bool measureDistanceMm(uint16_t* value);
private:
    uint8_t pinId;
    void requestPulse();
    bool measurePulseWidthUs(uint32_t* value);
};

#endif
