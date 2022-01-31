#pragma once

class IScene
{
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void Terminate() = 0;
};