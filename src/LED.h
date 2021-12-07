#pragma once
#include <gpio.h>
#include <stdint.h>

class LED{
public:
  LED(uint8_t pinMode);
  void Update(float updateTime);
private:
  Gpio* m_Gpio;
  bool m_Light;
  float m_Timer;
};
