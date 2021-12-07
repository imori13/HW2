#ifndef _TIMER_H_
#define _TIMER_H_

#include <Arduino.h>

#ifndef ESP32
class TimerUtil {
public:
    static void (*callback)();
    static uint8_t minCounter;
    static void enableFastPwm(uint8_t timerId, bool enabled);
    static void setComparedValue(uint8_t timerId, uint8_t value);
    static void setCallback(void (*callback)(), uint16_t frequency);
};
#endif

#endif
