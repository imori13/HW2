#include "GameSound.h"
#include "System/Timer.h"

#include <speaker.h>

namespace
{
    Speaker* s_pSpeaker;
    float s_Timer;

    bool flag;
}

namespace GameSound
{
    void Initialize(uint8_t pin)
    {
        s_pSpeaker = new Speaker(pin);
        flag = false;
    }

    void Update()
    {
        constexpr float limit = 1.0f;

        s_Timer += Timer::g_FrameTime;
        if(s_Timer > limit)
        {
            flag = !flag;
            s_Timer = 0;
            
            if(flag)
                s_pSpeaker->playTone(1000);
            else
                s_pSpeaker->stopTone();
        }
    }
}