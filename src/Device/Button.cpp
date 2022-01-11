#include "Button.h"
#include "Debug.h"

#include <Arduino.h>
#include <pinout.h>

namespace
{
    #define RELEASED false
    #define PUSHED true
}

Button::Button(uint8_t pin){
    m_pGpio = nullptr;
    m_pGpio = new Gpio(pin,Gpio::Mode::IN);
}

Button::~Button(){
    delete m_pGpio;
}

void Button::Update()
{
    InitializeState();
    bool state = m_pGpio->input();
    
    if(state == PUSHED && m_PrevState == RELEASED)
    {
        m_ButtonDown = true;
    }

    if(state == PUSHED)
    {
        m_ButtonHold = true;
    }

    if(state == RELEASED && m_PrevState == PUSHED)
    {
        m_ButtonUp = true;
    }

    // 前フレームのステートを保存
    m_PrevState = state;
}

void Button::InitializeState()
{
    m_ButtonDown = false;
    m_ButtonHold = false;
    m_ButtonUp = false;
}

bool Button::ButtonDown()
{
    return m_ButtonDown;
}

bool Button::ButtonHold()
{
    return m_ButtonHold;
}

bool Button::ButtonUp()
{
    return m_ButtonUp;
}
