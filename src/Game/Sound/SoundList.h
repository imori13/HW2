#pragma once
#include "SoundData.h"

enum class SoundEnum : uint8_t;

namespace SoundList
{
    void Initialize();
    SoundData GetSound(SoundEnum soundEnum);
}

enum class SoundEnum : uint8_t
{
    Test,
    GameClear,
    GameOver,

    Low,
    Middle,
    High,

    OK,
    Succsess,
    Misstake,
};
