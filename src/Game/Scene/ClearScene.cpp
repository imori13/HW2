#include "ClearScene.h"

#include "SceneManager.h"
#include "Game/StaticModules.h"

namespace
{
    float s_Timer;
    bool waitSceneChange;
    constexpr float FIRST_WAIT_LIMIT = 7.0f;
    constexpr float SECOUND_WAIT_LIMIT = 5.0f;
}

void ClearScene::Initialize()
{
    s_Timer = 0;
    waitSceneChange=false;

    GameSound::OnPlay(SoundEnum::GameClear);
}

void ClearScene::Update()
{
    s_Timer += Timer::g_FrameTime;
    if(!waitSceneChange)
    {
        StaticModules::g_ColorLED.OnLightBlink(Color::Blue(),0.075f);

        if(s_Timer >= FIRST_WAIT_LIMIT)
        {
            s_Timer=0;
            waitSceneChange=true;
        }
    }
    else
    {
        StaticModules::g_ColorLED.OnLightBlink(Color::Blue(),0.1f,1.0f);

        if(s_Timer >= SECOUND_WAIT_LIMIT)
        {
            s_Timer = 0;
            waitSceneChange = false;

            SceneManager::ChangeScene(SceneEnum::Ready);
        }
    }
}

void ClearScene::Terminate()
{

}