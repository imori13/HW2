#include "Button.h"
#include "System/Debug.h"

namespace
{
    constexpr bool RELEASED = false;
    constexpr bool PUSHED = true;
}

Button::Button(uint8_t pin)
{
    m_pGpio = new Gpio(pin,Gpio::Mode::IN);
}

void Button::Update()
{
    m_ButtonDown = false;
    m_ButtonHold = false;
    m_ButtonUp = false;

    bool state = m_pGpio->input();
    
    m_ButtonDown = (state == PUSHED && m_PrevState == RELEASED);
    m_ButtonHold = (state == PUSHED);
    m_ButtonUp = (state == RELEASED && m_PrevState == PUSHED);

    // 前フレームのステートを保存
    m_PrevState = state;
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
