#include "ReadyScene.h"

#include "SceneManager.h"
#include "Game/StaticModules.h"

namespace
{
    float s_LightOffTimer = 0;
    constexpr float s_LightOffLimit = 120.0f;

    float s_Timer;
    bool s_NextScene;
}

void ReadyScene::Initialize()
{
    s_Timer = 0;
    s_LightOffTimer = 0;
    s_NextScene = false;

    GameSound::OnPlay(SoundEnum::NO);
}

void ReadyScene::Update()
{
    if(s_LightOffTimer<s_LightOffLimit)
    {
        s_LightOffTimer += Timer::g_FrameTime;
        StaticModules::g_ColorLED.OnLightBlink(Color::Yellow(), 1.0f, 0.1f);
    }
    else
    {
        StaticModules::g_ColorLED.OffLight();
    }

    for(auto i = 0u; i < Input::size(); ++i)
    {
        if(Input::ButtonUp(i))
        {
            GameSound::OnPlay(SoundEnum::OK);
            s_NextScene = true;
        }
    }

    if(s_NextScene)
    {
        SceneManager::ChangeScene(SceneEnum::GamePlay);
    }
}

void ReadyScene::Terminate()
{

}