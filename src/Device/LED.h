#pragma once
#include "Device.h"

class LED : public Device{
public:
  LED(uint8_t pinMode);
  void Update(bool onoff);
  void BlinkUpdate(float updateTime);
private:
  bool m_Light;
  float m_LEDTimer;
};