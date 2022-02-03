#include "ReadyScene.h"

#include "SceneManager.h"
#include "StaticModules.h"

namespace
{
    float s_Timer;
    bool s_NextScene;
}

void ReadyScene::Initialize()
{
    s_Timer = 0;
    s_NextScene = false;

    GameSound::OnPlay(SoundEnum::GameClear);
}

void ReadyScene::Update()
{
    StaticModules::g_ColorLED.OnLightBlink(Color::Red(),0.75f);

    for(auto i = 0u; i < Input::size(); ++i)
    {
        if(Input::ButtonUp(i))
        {
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