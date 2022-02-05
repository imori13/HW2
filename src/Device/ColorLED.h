#pragma once
#include "Device.h"
#include "Color.h"
#include <ChainableLED.h>

class ColorLED
{
public:
  ColorLED(uint8_t pinMode);
  void OffLight();
  void OnLight(Color color);
  void OnLightBlink(Color color,float interval);
  void OnLightBlink(Color color,float waitTime, float lightTime);
private:
  ChainableLED* colorLED;
  bool m_Light;
  float m_LEDTimer;
};