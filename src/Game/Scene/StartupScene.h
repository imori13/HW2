#pragma once
#include "IScene.h"

class StartupScene : public IScene
{
public:
    ~StartupScene() override
    {
        Terminate();
    }
    void Initialize();
    void Update();
    void Terminate();
};