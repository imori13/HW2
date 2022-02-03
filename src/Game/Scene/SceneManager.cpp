#include "SceneManager.h"
#include "../../System/Debug.h"
#include "StartupScene.h"
#include "ReadyScene.h"
#include "GameScene.h"

namespace
{
    IScene* s_StartupScene;
    IScene* s_ReadyScene;
    IScene* s_GameScene;

    IScene* s_CurrentScene;
}

namespace SceneManager
{
    void Initialize()
    {
        s_StartupScene = new StartupScene();
        s_ReadyScene = new ReadyScene();
        s_GameScene = new GameScene();

        s_CurrentScene = nullptr;
    }

    void ChangeScene(SceneEnum sceneEnum)
    {
        Debug::LogLine("change scene.");
        
        switch(sceneEnum)
        {
            case SceneEnum::StartUp : 
                s_CurrentScene = s_StartupScene; break;
            case SceneEnum::Ready : 
                s_CurrentScene = s_ReadyScene; break;
            case SceneEnum::GamePlay : 
                s_CurrentScene = s_GameScene; break;

            default : 
                Debug::LogLine("change scene error."); break;
        }

        // scene initialize
        s_CurrentScene->Initialize();
    }

    void Update()
    {
        s_CurrentScene->Update();
    }
}