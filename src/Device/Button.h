#pragma once
#include "Device.h"

class Button : public Device
{
public:
    Button(uint8_t pin);
    void Update();

    bool ButtonDown();
    bool ButtonHold();
    bool ButtonUp();
private:
    bool m_PrevState;

    bool m_ButtonDown;
    bool m_ButtonHold;
    bool m_ButtonUp;
};