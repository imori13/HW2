#pragma once
#include "IScene.h"

class ReadyScene : public IScene
{
public:
    ~ReadyScene() override
    {
        Terminate();
    }
    void Initialize();
    void Update();
    void Terminate();
};