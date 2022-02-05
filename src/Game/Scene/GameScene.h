#pragma once
#include "IScene.h"

class GameScene : public IScene
{
public:
    ~GameScene() override
    {
        Terminate();
    }
    void Initialize();
    void Update();
    void Terminate();
};