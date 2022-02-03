#pragma once
#include "IScene.h"

class ReadyScene : public IScene
{
public:
    void Initialize();
    void Update();
    void Terminate();
};