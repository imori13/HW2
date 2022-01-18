#include "SoundList.h"

namespace
{
    SoundData s_Test;
    SoundData s_GameClear;
    SoundData s_GameOver;
}

namespace SoundList
{
    void Initialize()
    {
        // test
        {
            s_Test.loop_count = 1;
            s_Test.interval = 0.01f;
            for(auto i=10;i<100;++i)
                s_Test.set_next_tone(i);
            for(auto i=100;i>10;--i)
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