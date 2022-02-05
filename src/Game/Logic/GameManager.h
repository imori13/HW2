#pragma once
#include <stdint.h>

enum class GameLevel
{
    Level1,
    Level2,
    Level3,
    Level4,
    Level5,

    Max,
};

enum class PhaseState
{
    StartWait,
    SoundPhase, // 再生フェーズ
    InputPhase, // 入力フェーズ
    Succsess,   // 入力成功
    Misstake,    // 入力失敗
};

namespace GameManager
{
    extern bool IsSceneEnd;

    void Initialize();
    void Update();
    void ChangePhase(PhaseState nextState);

    GameLevel GetCurrentGameLevel();
};