#pragma once
#include <stdint.h>

class Button;
namespace Input
{
    void Initialize(uint8_t buttonLimit);
    void AddButton(uint8_t pin);
    void Update();

    bool GetDown(uint8_t index);
    bool GetHold(uint8_t index);
    bool GetUp(uint8_t index);
}