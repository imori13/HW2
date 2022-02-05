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
    GameManager::Update();

    if(GameManager::IsSceneEnd)
    {
        SceneManager::ChangeScene(SceneEnum::Ready);
    }

    if(GameManager::IsClear)
    {
        SceneManager::ChangeScene(SceneEnum::Clear);
    }
}

void GameScene::Terminate()
{
    GameManager::Terminate();
}