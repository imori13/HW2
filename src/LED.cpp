#include "LED.h"
#include "Debug.h"
#include "Timer.h"

LED::LED(uint8_t pinMode){
  m_Light = (pinMode==Pinout::LED);

  m_Gpio = nullptr;
  m_Gpio = new Gpio(pinMode,Gpio::Mode::OUT);
}

void LED::Update(float updateTime){
  m_Timer += Timer::g_FrameTime;

  if(m_Timer >= updateTime){
    m_Light = !m_Light;
    m_Gpio->output(m_Light);
    m_Light = 0;
  }
}
