#pragma once
#include <stdint.h>
#include "IScene.h"

enum class SceneEnum : uint8_t
{
    StartUp,
    ReadyToStart,
    GamePlay,
};

namespace SceneManager
{
    void AddScene(SceneEnum sceneEnum, IScene* scene);
    void ChangeScene(SceneEnum sceneEnum);
};