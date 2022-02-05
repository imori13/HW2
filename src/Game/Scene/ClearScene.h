#pragma once
#include "IScene.h"

class ClearScene : public IScene
{
public:
    ~ClearScene() override
    {
        Terminate();
    }
    void Initialize();
    void Update();
    void Terminate();
};