#include "ColorLED.h"

#include "System/Debug.h"
#include "System/Timer.h"

#include <pinout.h>

ColorLED::ColorLED(uint8_t pinMode)
{
  colorLED = new ChainableLED(pinMode, Pinout::D7, 1);
}

void ColorLED::OnLight(Color color)
{
    colorLED->setColorRGB(0, color.r, color.g, color.b);
}

void ColorLED::OnLightBlink(Color color,float blinkInterval)
{
    m_LEDTimer += Timer::g_FrameTime;

    if(m_LEDTimer >= blinkInterval)
    {
        m_Light = !m_Light;
        m_LEDTimer = 0;

        if(m_Light)
            colorLED->setColorRGB(0, color.r, color.g, color.b);
        else
            colorLED->setColorRGB(0, 0, 0, 0);
    }
}
