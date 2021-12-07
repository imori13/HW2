#pragma once
#include <stdint.h>

namespace Timer{
  extern double g_ElapsedTime;
  extern double g_FrameTime;

  void Update();
  void Delay(double delayTime);
}
