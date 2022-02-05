#include "ReadyScene.h"

#include "SceneManager.h"
#include "Game/StaticModules.h"

namespace
{
    float s_Timer;
    bool s_NextScene;
}

void ReadyScene::Initialize()
{
    s_Timer = 0;
    s_NextScene = false;

    GameSound::OnPlay(SoundEnum::OK);
}

void ReadyScene::Update()
{
    StaticModules::g_ColorLED.OnLightBlink(Color::Blue(), 1.0f, 0.1f);

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