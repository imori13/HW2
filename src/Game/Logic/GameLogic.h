#pragma once
#include "GameManager.h"

namespace GameLogic
{
    void Initialize();
    void Terminate();

    // 再生フェーズ
    void SoundPhase();
    // 入力フェーズ
    void InputPhase();
}