#include <timer_util.h>

#ifndef ESP32
ISR(TIMER2_OVF_vect) {
    TCNT2 = TimerUtil::minCounter;
    TimerUtil::callback();
}

void (*TimerUtil::callback)() = NULL;
uint8_t TimerUtil::minCounter = 0;

void TimerUtil::enableFastPwm(uint8_t timerId, bool enabled) {
    if (timerId == TIMER0A || timerId == TIMER0B) {
        TCCR0A = enabled ? (_BV(timerId == TIMER0A ? COM0A1 : COM0B1) | _BV(WGM01) | _BV(WGM00)) : 0x00;
        TCCR0B = enabled ? _BV(CS00) : (_BV(CS01) | _BV(CS00));
    } else if (timerId == TIMER1A || timerId == TIMER1B) {
        TCCR1A = enabled ? (_BV(timerId == TIMER1A ? COM1A1 : COM1B1) | _BV(WGM10)) : 0x00;
        TCCR1B = enabled ? (_BV(WGM12) | _BV(CS10)) : (_BV(CS11) | _BV(CS10));
    } else if (timerId == TIMER2A || timerId == TIMER2B) {
        TCCR2A = enabled ? (_BV(timerId == TIMER2A ? COM2A1 : COM2B1) | _BV(WGM21) | _BV(WGM20)) : 0x00;
        TCCR0B = enabled ? _BV(CS20) : _BV(CS22);
    }
}

void TimerUtil::setComparedValue(uint8_t timerId, uint8_t value) {
    if (timerId == TIMER0A) {
        OCR0A = value;
    } else if (timerId == TIMER0B) {
        OCR0B = value;
    } else if (timerId == TIMER1A) {
        OCR1A = value;
    } else if (timerId == TIMER1B) {
        OCR1B = value;
    } else if (timerId == TIMER2A) {
        OCR2A = value;
    } else if (timerId == TIMER2B) {
        OCR2B = value;
    }
}

void TimerUtil::setCallback(void (*callback)(), uint16_t frequency) {
    if (callback != NULL) {
        const uint16_t maxCounter = 256;
        const uint8_t clockDivider = 8;
        TimerUtil::callback = callback;
        TimerUtil::minCounter = maxCounter - min(F_CPU / clockDivider / frequency, maxCounter);
        TCCR2A = 0x00;
        TCCR2B = _BV(CS21);
        TCNT2 = 0xff;
        TIMSK2 = _BV(TOIE2);
    } else {
        TIMSK2 = 0x00;
    }
}
#endif
