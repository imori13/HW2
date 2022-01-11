#pragma once
#include "LED.h"

class LEDcolor : public LED
{
public:
    void Game_Right();
    void Game_Miss();
private:
    float m_Timer;
};