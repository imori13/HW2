#include <Arduino.h>
#include <gpio.h>
#include <timer_util.h>
#include <speaker.h>

Speaker::Speaker(uint8_t pinId) {
    this->pinId = pinId;
}

void Speaker::playTone(uint16_t frequency, uint32_t durationMs) {
    if (durationMs > 0) {
        tone(this->pinId, frequency, durationMs);
    } else {
        tone(this->pinId, frequency);
    }
}

void Speaker::stopTone() {
    noTone(this->pinId);
}

void Speaker::playSound(const uint8_t* sound, uint16_t length, uint16_t frequency, bool isAsync) {
    if (this->dac == NULL) {
        this->dac = new Gpio(this->pinId, Gpio::Mode::DAC);
    }
    this->playing = sound;
    this->eof = sound + length;
#ifdef ESP32
    const uint16_t interval = (uint32_t)1 * 1000 * 1000 / frequency;
    for (; this->playing < this->eof; this->playing++) {
        dac->outputAnalog(pgm_read_byte_near(this->playing));
        delayMicroseconds(interval);
    }
    this->stopSound();
#else
    this->self = this;
    TimerUtil::setCallback(this->playStep, frequency);
    if (!isAsync) {
        while (this->dac != NULL) {
            delay(10);
        }
    }
#endif
}

void Speaker::stopSound() {
    if (this->dac == NULL) return;
#ifndef ESP32
    TimerUtil::setCallback(NULL, 0);
#endif
    delete this->dac;
    this->dac = NULL;
}

Speaker* Speaker::self = NULL;

void Speaker::playStep() {
    self->dac->outputAnalog(pgm_read_byte_near(self->playing));
    self->playing++;
    if (self->playing == self->eof) {
        self->stopSound();
    }
}
