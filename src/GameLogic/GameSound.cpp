#include "GameSound.h"
#include "System/Timer.h"
#include "Sound/SoundData.h"

#include <speaker.h>

// constant information.
namespace
{
    constexpr uint8_t convert_tone_height = 10u;
}

// sound play data.
namespace
{
    SoundData soundData;
    uint8_t tone_index = 0;
    uint8_t loop_index = 0;
}

namespace
{
    Speaker* s_pSpeaker;
    float s_Timer;

    bool s_Play;
}

namespace GameSound
{
    void Initialize(uint8_t pin)
    {
        s_pSpeaker = new Speaker(pin);
        s_Play = false;

        soundData.loop_count = 1;
        soundData.interval = 0.01f;
        for(auto i=10;i<100;++i)
            soundData.set_next_tone(i);
        for(auto i=100;i>10;--i)
            soundData.set_next_tone(i);
    }

    void Update()
    {
        if(s_Play)
        {
            s_Timer += Timer::g_FrameTime;

            if( s_Timer > soundData.interval )
            {
                if( tone_index < soundData.size())
                {
                    const auto& tone = soundData.at(tone_index);
                    if(tone != 0)
                        s_pSpeaker->playTone(tone * convert_tone_height);
                    else
                        s_pSpeaker->stopTone();
                    ++tone_index;

                    s_Timer = 0;
                }
                else
                {
                    ++loop_index;
                    if( loop_index < soundData.loop_count ) // continue to play sound
                    {
                        s_pSpeaker->stopTone();
                        tone_index = 0;
                    }
                    else // break to play sound
                    {
                        s_pSpeaker->stopTone();
                        s_Play = false;
                        tone_index = 0;
                        loop_index = 0;
                    }
                }
            }
        }
    }

    void OnPlay()
    {
        s_Play = true;
        s_Timer = 0;
        tone_index = 0;
        loop_index = 0;
    }
}