#include "GameScene.h"
#include "../GameSound.h"
#include "StaticModules.h"

void GameScene::Initialize()
{
    
}

void GameScene::Update()
{
    StaticModules::g_ColorLED.OnLight(Color::Green());
    
    for(auto i=0u; i<Input::size(); ++i)
    {
        if(Input::ButtonUp(i))
        {
            Debug::Log("Button Pushed : ");
            Debug::LogLine(i);
        }
    }

    if(Input::ButtonHold(0) || Input::ButtonHold(1) || Input::ButtonHold(2))
    {
        StaticModules::g_ColorLED.OnLightBlink(Color::Red(), 0.1f);
    }

    if(Input::ButtonUp(0))
    {
        GameSound::OnPlay(SoundEnum::Test);
    }

    if(Input::ButtonUp(1))
    {
        GameSound::OnPlay(SoundEnum::GameClear);
    }

    if(Input::ButtonUp(2))
    {
        GameSound::OnPlay(SoundEnum::GameOver);
    }
}

void GameScene::Terminate()
{

}