#include "GameManager.h"
#include "Game/StaticModules.h"
#include "GameLogic.h"

namespace
{
    // 現在のゲームレベル
    GameLevel s_CurrentGameLevel;
    // 現在のゲームフェーズ
    PhaseState s_CurrentLevelState;

    float s_Timer;
    bool s_SuccsessStart;
    bool s_MisstakeStart;
}

namespace
{ 
    bool IsLastLevel()
    {
        return (GameLevel)((uint8_t)s_CurrentGameLevel+1) == GameLevel::Max;
    }

    void GameLevelUp()
    {
        s_CurrentGameLevel = (GameLevel)((uint8_t)s_CurrentGameLevel+1);
    }

    void WaitUpdate()
    {
        StaticModules::g_ColorLED.OnLightBlink(Color::Red(),0.1f,1.0f);

        constexpr float WAIT_LIMIT = 1.0f;

        s_Timer += Timer::g_FrameTime;
        if(s_Timer > WAIT_LIMIT)
        {
            s_Timer = 0;
            GameManager::ChangePhase(PhaseState::SoundPhase);
        }
    }

    void SoundPhaseUpdate()
    {
        StaticModules::g_ColorLED.OnLightBlink(Color::Red(),0.1f);
        GameLogic::SoundPhase();
    }

    void InputPhaseUpdate()
    {
        StaticModules::g_ColorLED.OnLightBlink(Color::Blue(),1.0,0.1f);
        GameLogic::InputPhase();
    }

    void SuccsessPhaseUpdate()
    {
        constexpr float SUCCSESS_FIRST_WAIT_LIMIT = 0.5f;
        constexpr float SUCCSESS_SECOUND_WAIT_LIMIT = 3.0f;

        if(!s_SuccsessStart)
        {
            s_Timer += Timer::g_FrameTime;
            if(s_Timer > SUCCSESS_FIRST_WAIT_LIMIT)
            {
                s_Timer = 0;
                s_SuccsessStart = true;

                GameSound::OnPlay(SoundEnum::Succsess);
            }
        }
        else
        {
            StaticModules::g_ColorLED.OnLightBlink(Color::Green(),0.1f,1.0f);

            // 次のレベルへ
            s_Timer += Timer::g_FrameTime;
            if(s_Timer > SUCCSESS_SECOUND_WAIT_LIMIT)
            {
                if(IsLastLevel())
                {
                    s_Timer = 0;
                    s_SuccsessStart = false;
                    GameManager::ChangePhase(PhaseState::StartWait);
                    GameManager::IsClear = true;
                }
                else
                {
                    GameLevelUp();

                    s_Timer = 0;
                    s_SuccsessStart = false;
                    GameManager::ChangePhase(PhaseState::SoundPhase);
                }
            }
        }
    }

    void MisstakePhaseUpdate()
    {
        constexpr float MISSTAKE_FIRST_WAIT_LIMIT = 0.5f;
        constexpr float MISSTAKE_SECOUND_WAIT_LIMIT = 3.0f;

        if(!s_MisstakeStart)
        {
            s_Timer += Timer::g_FrameTime;
            if(s_Timer > MISSTAKE_FIRST_WAIT_LIMIT)
            {
                s_Timer = 0;
                s_MisstakeStart = true;

                GameSound::OnPlay(SoundEnum::Misstake);
            }
        }
        else
        {
            StaticModules::g_ColorLED.OnLightBlink(Color::Red(),0.1f,1.0f);
            
            // 最初に戻る
            s_Timer += Timer::g_FrameTime;
            if(s_Timer > MISSTAKE_SECOUND_WAIT_LIMIT)
            {
                s_Timer = 0;
                s_MisstakeStart = false;
                GameManager::ChangePhase(PhaseState::StartWait);
                GameManager::IsSceneEnd = true;
            }
        }
    }
}

namespace GameManager
{
    bool IsSceneEnd; // extern GameManager.h
    bool IsClear;

    void Initialize()
    {
        IsSceneEnd = false;
        IsClear=false;
        s_Timer = 0;
        s_SuccsessStart = false;
        s_MisstakeStart = false;
        s_CurrentGameLevel = GameLevel::Level1;
        ChangePhase(PhaseState::StartWait);
        GameLogic::Initialize();
    }

    void Update()
    {
        switch (s_CurrentLevelState)
        {
            // 開始待機
            case PhaseState::StartWait: 
                WaitUpdate();
                break;
            
            // サウンド再生フェーズ
            case PhaseState::SoundPhase: 
                SoundPhaseUpdate();
                break;

            // 入力フェーズ
            case PhaseState::InputPhase: 
                InputPhaseUpdate();
                break;

            // 成功時
            case PhaseState::Succsess: 
                SuccsessPhaseUpdate();
                break;

            // 失敗時
            case PhaseState::Misstake:
                MisstakePhaseUpdate();
                break;
            
            default: break;
        }
    }

    void Terminate()
    {
        GameLogic::Terminate();
    }

    void ChangePhase(PhaseState nextState)
    {
        s_CurrentLevelState = nextState;
        Debug::Log("change levelState : ");
        Debug::LogLine((uint8_t)nextState);
    }

    GameLevel GetCurrentGameLevel()
    {
        return s_CurrentGameLevel;
    }
}