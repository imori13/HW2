#pragma once
#include "SoundData.h"

namespace SoundPlayer
{
    void Initialize(uint8_t pin);
    void Update();
    void OnPlay(const SoundData& soundData);
}