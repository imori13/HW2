#include "Timer.h"
#include <Arduino.h>

namespace{
  constexpr double s_Modular = 1000;  // 1秒単位のdoubleで扱いたいので1000ms割る
  constexpr uint64_t s_MilliFrame = 16;
  uint64_t s_MilliElapsed = 0;
  uint64_t s_DestFrame = 0; // 1フレーム経過後のミリ秒
}

namespace Timer{
  double g_ElapsedTime = 0;
  double g_FrameTime = s_MilliFrame / s_Modular;

  void Update(){
    g_ElapsedTime = millis() / s_Modular;

    // 1frame待機
    do{
      s_MilliElapsed = millis();
    }while(s_MilliElapsed < s_DestFrame);
    s_DestFrame += s_MilliFrame;
  }

  // 待機
  void Delay(double delayTime)
  { delay(static_cast<uint64_t>(delayTime*s_Modular)); }
}
