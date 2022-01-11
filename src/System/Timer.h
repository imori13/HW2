#pragma once
#include <stdint.h>

namespace Timer
{
  constexpr double g_FrameTime = 1.0 / 60.0;

  extern double g_ElapsedTime;

  void Update();
  void Delay(double delayTime);
}
