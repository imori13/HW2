#pragma once
#include "Sound/SoundList.h"
#include <stdint.h>

namespace GameSound
{
    void Initialize(uint8_t pin);
    void Update();
    void OnPlay(SoundEnum soundEnum);
};