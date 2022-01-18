#include "SoundPlayer.h"
#include "System/Timer.h"
#include <speaker.h>

// constant information.
namespace
{
    constexpr uint8_t convert_tone_height = 10u;
}

// static value.
namespace
{
    Speaker* s_pSpeaker;
    SoundData s_SoundData;

    bool s_Play;
    float s_Timer;
    uint8_t s_iTone = 0;
    uint8_t s_iLoop = 0;
}

// play method.
namespace
{
    void Reset(bool isPlay)
    {
        s_pSpeaker->stopTone();
        s_Play = isPlay;
        s_Timer = 0;
        s_iTone = 0;
        s_iLoop = 0;
    }

    void Play()
    {
        if(!s_Play) return;

        s_Timer += Timer::g_FrameTime;

        if( s_Timer < s_SoundData.interval ) return;

        // 再生
        if( s_iTone < s_SoundData.size())
        {
            const auto& tone = s_SoundData.at(s_iTone);
            if(tone != 0)
                s_pSpeaker->playTone(tone * convert_tone_height);
            else
                s_pSpeaker->stopTone();
            ++s_iTone;

            s_Timer = 0;
        }
        // ループするか？
        else
        {
            s_pSpeaker->stopTone();

            if( s_iLoop + 1 < s_SoundData.loop_count ) // continue to play sound
            {
                s_iTone = 0;
                ++s_iLoop;
            }
            else // break to play sound
            {
                Reset(false);
            }
        }
    }
}

namespace SoundPlayer
{
    void Initialize(uint8_t pin)
    {
        s_pSpeaker = new Speaker(pin);
        s_Play = false;
    }

    void Update()
    {
        Play();
    }

    void OnPlay(const SoundData& soundData)
    {
        s_SoundData = soundData;
        Reset(true);
    }
}