#include "GameLogic.h"
#include "SoundArray.h"
#include "Game/StaticModules.h"

namespace
{
    // レベルごとの音階データ
    SoundArray* s_LevelSound;

    // 再生用
    uint8_t s_SoundPlayIndex;
    float s_Timer;

    // 入力用
    uint8_t s_InputIndex;
}

namespace
{
    SoundEnum ToSound(SoundInterval soundInterval)
    {
        switch (soundInterval)
        {
            case SoundInterval::Low: return SoundEnum::Low;
            case SoundInterval::Middle: return SoundEnum::Middle;
            case SoundInterval::High: return SoundEnum::High;
            default : Debug::LogLine("convet error in GameLogic.cpp/ToSound()"); return SoundEnum::Test;
        }
    }

    SoundArray& GetLevelSound()
    {
        return s_LevelSound[(uint8_t)GameManager::GetCurrentGameLevel()];
    }

    bool IsAnyBottonUp()
    {
        return Input::ButtonUp(0) || Input::ButtonUp(1) || Input::ButtonUp(2);
    }

    bool CheckSameSound(SoundInterval nextSound)
    {
        bool retVal = false;
        if(Input::ButtonUp(0)) retVal = (nextSound == SoundInterval::Low);
        if(Input::ButtonUp(1)) retVal = (nextSound == SoundInterval::Middle);
        if(Input::ButtonUp(2)) retVal = (nextSound == SoundInterval::High);

        return retVal;
    }

    SoundInterval GetPushedButton()
    {
        if(Input::ButtonUp(0)) return SoundInterval::Low;
        if(Input::ButtonUp(1)) return SoundInterval::Middle;
        if(Input::ButtonUp(2)) return SoundInterval::High;

        Debug::LogLine("error in GameLogic.cpp/GetPushedButton()");
        return SoundInterval::High;
    }
}

namespace GameLogic
{   
    void Initialize()
    {
        s_SoundPlayIndex = 0;
        s_InputIndex = 0;

        // ■ レベルごとの配列を生成
        s_LevelSound = new SoundArray[(uint8_t)GameLevel::Max];
        for(auto iLevel = 0; iLevel<(uint8_t)GameLevel::Max; ++iLevel)
        {
            const auto& size = iLevel+5;
            s_LevelSound[iLevel].Create(size);
            
            // ■ レベル内の音程を生成
            for(auto iSize = 0; iSize < size; ++ iSize)
            {
                s_LevelSound[iLevel].at(iSize) = SoundInterval::Low;
            }
        }
        s_LevelSound[(uint8_t)GameLevel::Level1].Create(3);
        s_LevelSound[(uint8_t)GameLevel::Level1].at(0) = SoundInterval::Low;
        s_LevelSound[(uint8_t)GameLevel::Level1].at(1) = SoundInterval::Middle;
        s_LevelSound[(uint8_t)GameLevel::Level1].at(2) = SoundInterval::High;
    }

    // 再生フェーズ
    void SoundPhase()
    {
        constexpr float SOUND_PLAY_INTERVAL = 1.0f;

        // 現在のレベルのサウンド配列を取り出す
        const auto& levelSound = GetLevelSound();

        s_Timer += Timer::g_FrameTime;
        if(s_Timer > SOUND_PLAY_INTERVAL)
        {
            s_Timer = 0;

            if(s_SoundPlayIndex < levelSound.size())
            {
                GameSound::OnPlay(ToSound(levelSound.at(s_SoundPlayIndex)));
                ++s_SoundPlayIndex;
            }
            // 再生終了
            else
            {
                GameManager::ChangePhase(PhaseState::InputPhase);
                s_SoundPlayIndex = 0;
            }
        }
    }

    // 入力フェーズ
    void InputPhase()
    {
        if(IsAnyBottonUp())
        {
            // 現在のレベルのサウンド配列を取り出す
            const auto& levelSound = GetLevelSound();

            if(s_InputIndex < levelSound.size())
            {
                const auto& nextSound = levelSound.at(s_InputIndex);

                // 押したボタンの音を再生
                GameSound::OnPlay(ToSound(GetPushedButton()));

                // 成功
                if(CheckSameSound(nextSound))
                {
                    ++s_InputIndex;

                    // すべて成功していたら次のレベルへ
                    if(s_InputIndex >= levelSound.size())
                    {
                        s_InputIndex = 0;
                        GameManager::ChangePhase(PhaseState::Succsess);
                    }
                }
                // 失敗
                else
                {
                    s_InputIndex = 0;
                    // ミステイクフェーズへ遷移
                    GameManager::ChangePhase(PhaseState::Misstake);
                }
            }
        }
    }
}