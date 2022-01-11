#pragma once
#include <gpio.h>
#include <stdint.h>

class Button
{
public:
    Button(uint8_t pin);
    ~Button();
    void Update();

    bool ButtonDown();
    bool ButtonHold();
    bool ButtonUp();
private:
    void InitializeState();

    bool m_PrevState; 
    Gpio* m_pGpio;

    bool m_ButtonDown;
    bool m_ButtonHold;
    bool m_ButtonUp;
};