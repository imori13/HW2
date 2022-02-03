#pragma once
#include "Device.h"
#include "Color.h"
#include <ChainableLED.h>

class ColorLED
{
public:
  ColorLED(uint8_t pinMode);
  void OnLight(Color color);
  void OnLightBlink(Color color,float blinkInterval);
private:
  ChainableLED* colorLED;
  bool m_Light;
  float m_LEDTimer;
};