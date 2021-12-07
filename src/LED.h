#pragma once
#include <gpio.h>
#include <stdint.h>

class LED{
public:
  LED(uint8_t pinMode);
  void Update(float updateTime);

private:
  Gpio* gpio;
  bool m_isLED;
};
