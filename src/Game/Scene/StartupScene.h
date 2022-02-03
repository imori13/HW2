#pragma once
#include "IScene.h"

class StartupScene : public IScene
{
public:
    void Initialize();
    void Update();
    void Terminate();
};