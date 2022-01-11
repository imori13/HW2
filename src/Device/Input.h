#pragma once
#include <stdint.h>

class Button;
namespace Input
{
    void Initialize(uint8_t buttonLimit);
    void AddButton(uint8_t pin);
    void Update();

    bool ButtonDown(uint8_t index);
    bool ButtonHold(uint8_t index);
    bool ButtonUp(uint8_t index);
}