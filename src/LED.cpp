#include "LED.h"
#include "Debug.h"
#include "Timer.h"

LED::LED(uint8_t pinMode){
  m_Light = (pinMode==Pinout::LED);

  m_pGpio = nullptr;
  m_pGpio = new Gpio(pinMode,Gpio::Mode::OUT);
}

LED::~LED(){
  delete m_pGpio;
}

void LED::Update()
{

}

void LED::BlinkUpdate(float updateTime){
  m_LEDTimer += Timer::g_FrameTime;

  if(m_LEDTimer >= updateTime){
    m_Light = !m_Light;
    m_pGpio->output(m_Light);
    m_LEDTimer = 0;
  }
}
