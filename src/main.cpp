#include <Arduino.h>
#include <pinout.h>

#include "Debug.h"
#include "Timer.h"
#include "LED.h"


namespace {
    LED baseLED(Pinout::LED);
    LED moduleLED(Pinout::D6_PWM_READY);
}

void setup() {
    Serial.begin(115200);
}

void loop() {
    Timer::Update();

    baseLED.Update(0.1f);
    moduleLED.Update(0.1f);
}
