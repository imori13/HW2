#include "LED.h"
#include "Debug.h"
#include "Timer.h"


LED::LED(uint8_t pinMode){
  m_isLED = (pinMode==Pinout::LED);

  gpio = nullptr;
  gpio = new Gpio(pinMode,Gpio::Mode::OUT);
}

void LED::Update(float updateTime){
  // オン
  gpio->output(m_isLED);
  Timer::Delay(updateTime);

  // オフ
  gpio->output(!m_isLED);
  Timer::Delay(updateTime);
}
