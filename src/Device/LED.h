#pragma once
#include <gpio.h>
#include <stdint.h>

class LED{
public:
  LED(uint8_t pinMode);
  virtual ~LED();
  void Update();
  void BlinkUpdate(float updateTime);
protected:
  Gpio* m_pGpio;
private:
  bool m_Light;
  float m_LEDTimer;
};
