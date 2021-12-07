#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include <stdint.h>
#include <gpio.h>

class Speaker {
public:
    Speaker(uint8_t pinId);
    void playTone(uint16_t frequency, uint32_t durationMs = 0);
    void stopTone();
    void playSound(const uint8_t* sound, uint16_t length, uint16_t frequency, bool isAsync = false);
    void stopSound();
private:
    static Speaker* self;
    static void playStep();
    uint8_t pinId;
    Gpio* dac = NULL;
    const uint8_t* playing;
    const uint8_t* eof;
};

#endif
