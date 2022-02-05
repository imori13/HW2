#include "GameScene.h"
#include "../GameSound.h"
#include "Game/StaticModules.h"
#include "Game/Logic/GameManager.h"
#include "SceneManager.h"

void GameScene::Initialize()
{
    GameManager::Initialize();
}

void GameScene::Update()
{
    // if(Input::ButtonUp(0))
    // {
    //     GameSound::OnPlay(SoundEnum::Low);
    // }

    // if(Input::ButtonUp(1))
    // {
    //     GameSound::OnPlay(SoundEnum::Middle);
    // }

    // if(Input::ButtonUp(2))
    // {
    //     GameSound::OnPlay(SoundEnum::High);
    // }

    GameManager::Update();

    if(GameManager::IsSceneEnd)
    {
        SceneManager::ChangeScene(SceneEnum::Ready);
    }
}

void GameScene::Terminate()
{

}