#include "StartupScene.h"

#include "SceneManager.h"
#include "Game/StaticModules.h"

namespace 
{
    float s_Timer;
    constexpr float LIMIT = 2.0f;
}

void StartupScene::Initialize()
{
    Debug::LogLine("StartupScene : start");

    s_Timer = 0;
    GameSound::OnPlay(SoundEnum::Succsess);
}

void StartupScene::Update()
{
    StaticModules::g_ColorLED.OnLightBlink(Color::White(),0.1f);

    s_Timer += Timer::g_FrameTime;
    if(s_Timer >= LIMIT)
    {
        Debug::LogLine("StartupScene : finished");

        SceneManager::ChangeScene(SceneEnum::Ready);
    }
}

void StartupScene::Terminate()
{
    
}