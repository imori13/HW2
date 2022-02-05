#include "SceneManager.h"
#include "../../System/Debug.h"
#include "StartupScene.h"
#include "ReadyScene.h"
#include "GameScene.h"
#include "ClearScene.h"

namespace
{
    IScene* s_CurrentScene;
}

namespace SceneManager
{
    void Initialize()
    {
        s_CurrentScene = nullptr;
    }

    void ChangeScene(SceneEnum sceneEnum)
    {
        Debug::Log("change scene : ");
        Debug::LogLine((uint8_t) sceneEnum);
        
        if(s_CurrentScene!=nullptr)
        {
            delete s_CurrentScene;

            Debug::LogLine("scene terminated.");
        }

        switch(sceneEnum)
        {
            case SceneEnum::StartUp :  s_CurrentScene = new StartupScene(); break;
            case SceneEnum::Ready :  s_CurrentScene = new ReadyScene(); break;
            case SceneEnum::GamePlay :  s_CurrentScene = new GameScene(); break;
            case SceneEnum::Clear :  s_CurrentScene = new ClearScene(); break; 

            default : Debug::LogLine("change scene error."); break;
        }

        // scene initialize
        s_CurrentScene->Initialize();
        Debug::LogLine("scene initialize.");
    }

    void Update()
    {
        s_CurrentScene->Update();
    }
}