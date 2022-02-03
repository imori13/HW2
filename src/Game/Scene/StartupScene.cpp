#include "StartupScene.h"

#include "SceneManager.h"
#include "StaticModules.h"

namespace 
{
    float s_Timer;
    constexpr float LIMIT = 2.0f;
}

void StartupScene::Initialize()
{
    s_Timer = 0;
    
    GameSound::OnPlay(SoundEnum::Test);

    Debug::LogLine("StartupScene : start");
}

void StartupScene::Update()
{
    StaticModules::g_ColorLED.OnLightBlink(Color::Red(),0.1f);

    s_Timer += Timer::g_FrameTime;
    if(s_Timer >= LIMIT)
    {
        SceneManager::ChangeScene(SceneEnum::Ready);

        Debug::LogLine("StartupScene : finished");
    }
}

void StartupScene::Terminate()
{
    
}