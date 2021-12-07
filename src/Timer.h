#pragma once
#include <stdint.h>

namespace Timer{
  constexpr double g_FrameTime = 0.016666;
  extern double g_ElapsedTime;

  void Update();
  void Delay(double delayTime);
}
