#pragma once
#include "IScene.h"
#include "SceneEnum.h"

namespace SceneManager
{
    void ChangeScene(SceneEnum sceneEnum);
    void Initialize();
    void Update();
};