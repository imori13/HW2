#include "SoundList.h"

namespace
{
    SoundData s_Startup;
    SoundData s_Test;
    SoundData s_GameClear;
    SoundData s_GameOver;
}

namespace SoundList
{
    void Initialize()
    {
        // startup 
        {
            s_Startup.loop_count = 1;
            s_Startup.interval = 0.25f;
            s_Startup.set_next_tone(100);
        }

        // test
        {
            s_Test.loop_count = 1;
            s_Test.interval = 0.05f;
            for(auto i=10;i<25;++i)
                s_Test.set_next_tone(i);
            for(auto i=25;i>10;--i)
                s_Test.set_next_tone(i);
        }

        // clear
        {
            s_GameClear.loop_count = 10;
            s_GameClear.interval = 0.1f;
            s_GameClear.set_next_tone(100);
            s_GameClear.set_next_tone(50);
        }

        // gameover
        {
            s_GameOver.loop_count = 1;
            s_GameOver.interval = 0.5f;
            s_GameOver.set_next_tone(100);
            s_GameOver.set_next_tone(70);
            s_GameOver.set_next_tone(50);
            s_GameOver.set_next_tone(30);
            s_GameOver.set_next_tone(30);
        }
    }

    SoundData GetSound(SoundEnum soundName)
    {
        switch(soundName)
        {
            case SoundEnum::Test:
                return s_Test;
            case SoundEnum::GameClear:
                return s_GameClear;
            case SoundEnum::GameOver:
                return s_GameOver;
            default :
                return s_Test;
        }

        return s_Test;
    }
}