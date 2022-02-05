#include "ColorLED.h"

#include "System/Debug.h"
#include "System/Timer.h"

#include <pinout.h>

ColorLED::ColorLED(uint8_t pinMode)
{
  colorLED = new ChainableLED(pinMode, Pinout::A1, 1);
}

void ColorLED::OnLight(Color color)
{
    colorLED->setColorRGB(0, color.r, color.g, color.b);
}

void ColorLED::OnLightBlink(Color color,float interval)
{
    m_LEDTimer += Timer::g_FrameTime;

    if(m_LEDTimer >= interval)
    {
        m_Light = !m_Light;
        m_LEDTimer = 0;

        if(m_Light)
            colorLED->setColorRGB(0, color.r, color.g, color.b);
        else
            colorLED->setColorRGB(0, 0, 0, 0);
    }
}

void ColorLED::OnLightBlink(Color color,float waitTime, float lightTime)
{
    m_LEDTimer += Timer::g_FrameTime;

    if(m_Light)
    {
        if(m_LEDTimer >= lightTime)
        {
            m_Light = false;
            m_LEDTimer = 0;

            colorLED->setColorRGB(0, 0, 0, 0);
        }
    }
    else
    {
        if(m_LEDTimer >= waitTime)
        {
            m_Light = true;
            m_LEDTimer = 0;

            colorLED->setColorRGB(0, color.r, color.g, color.b);
        }
    }
}
