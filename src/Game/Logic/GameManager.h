#pragma once
#include <stdint.h>

enum class GameLevel
{
    Level1,
    Level2,

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
    extern bool IsClear;

    void Initialize();
    void Update();
    void Terminate();
    void ChangePhase(PhaseState nextState);

    GameLevel GetCurrentGameLevel();
};