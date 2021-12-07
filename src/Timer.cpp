#include "Timer.h"
#include <Arduino.h>

namespace{
  constexpr double s_Modular = 1000;  // 1秒単位のdoubleで扱いたいので1000ms割る
  double s_DestFrame = 0; // 1フレーム経過後のミリ秒
}

namespace Timer{
  double g_ElapsedTime = 0;

  void Update(){
    // 1frame分待機
    do{
      g_ElapsedTime = millis() / s_Modular;
    }while(g_ElapsedTime < s_DestFrame);
    s_DestFrame += g_FrameTime;
  }

  // 待機
  void Delay(double delayTime)
  { delay(static_cast<uint64_t>(delayTime*s_Modular)); }
}
