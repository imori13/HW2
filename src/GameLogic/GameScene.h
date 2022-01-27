#pragma once
#include <stdint.h>

enum class GameState : uint8_t
{
    StandBy, // スタンバイ
    GamePlay, // プレイ中
};

namespace GameScene
{
    extern GameState g_GameState;

    void Initialize();
    void Update();
}