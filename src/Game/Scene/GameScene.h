#pragma once
#include "IScene.h"

class GameScene : public IScene
{
public:
    void Initialize();
    void Update();
    void Terminate();
};