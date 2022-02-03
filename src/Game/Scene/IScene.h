#pragma once
#include "SceneEnum.h"

class IScene
{
public:
    virtual ~IScene() {} 
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void Terminate() = 0;
};