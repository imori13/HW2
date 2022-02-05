#include "SoundList.h"

namespace
{
    SoundData s_Low;
    SoundData s_Middle;
    SoundData s_High;

    SoundData s_OK;
    SoundData s_Succsess;
    SoundData s_Misstake;

    SoundData s_GameClear;
}

namespace SoundList
{
    void Initialize()
    {
        // gamesounds.
        {
            constexpr uint8_t loopCount = 1;
            constexpr float gamesound_interval = 0.001f;

            constexpr int arraysize = 7;
            constexpr uint8_t array[arraysize] = {80,110,85,105,90,100,95};

            s_Low.loop_count = loopCount;
            s_Middle.loop_count = loopCount;
            s_High.loop_count = loopCount;
            s_Low.interval = gamesound_interval;
            s_Middle.interval = gamesound_interval;
            s_High.interval = gamesound_interval;

            for(auto i= 0;i<arraysize;++i)
            {
                s_Low.set_next_tone(array[i]+20);
                s_Low.set_next_tone(array[i]-20);
                s_Middle.set_next_tone(array[i]+40);
                s_Middle.set_next_tone(array[i]+50);
                s_High.set_next_tone(array[i]+100);
                s_High.set_next_tone(array[i]+120);
            }
        }

        // OK
        {
            s_OK.loop_count = 1;
            s_OK.interval = 0.05f;
            s_OK.set_next_tone(50);
            s_OK.set_next_tone(0);
            s_OK.set_next_tone(100);
            s_OK.set_next_tone(150);
            s_OK.set_next_tone(0);
            s_OK.set_next_tone(200);
        }

        // Succsess
        {
            s_Succsess.loop_count = 1;
            s_Succsess.interval = 0.05f;

            for(auto i=0;i<5;++i)
            {
                for(auto j=0;j<5;++j)
                {
                    s_Succsess.set_next_tone(100+(i*10)+(j*10));
                }
            }
            for(auto i=0;i<10;++i)
            {
                s_Succsess.set_next_tone(50+i*10);
                s_Succsess.set_next_tone(100+i*10);
            }
        }

        // Misstake
        {
            s_Misstake.loop_count = 1;
            s_Misstake.interval = 0.025f;
            s_Misstake.set_next_tone(200);
            s_Misstake.set_next_tone(0);
            s_Misstake.set_next_tone(100);
            s_Misstake.set_next_tone(200);
            s_Misstake.set_next_tone(0);
            s_Misstake.set_next_tone(100);
            s_Misstake.set_next_tone(200);
            s_Misstake.set_next_tone(0);
            s_Misstake.set_next_tone(100);
            s_Misstake.set_next_tone(200);
            s_Misstake.set_next_tone(0);
            s_Misstake.set_next_tone(100);
            for(auto i=2;i>=0;--i)
            {
                for(auto j=3;j>=0;--j)
                {
                    s_Misstake.set_next_tone(50+(i*5)+(j*5));
                    s_Misstake.set_next_tone(100+(i*5)+(j*5));
                }
            }
            for(auto i=10;i>=0;--i)
            {
                s_Misstake.set_next_tone(0+i*5);
                s_Misstake.set_next_tone(50+i*5);
            }
        }
        // clear
        {
            constexpr int arraysize = 32;
            constexpr uint8_t array[arraysize] = {100,0,100,0,100,0,100,100,100,0,80,80,80,80,90,90,90,90,100,100,0,0,90,0,100,100,100,100,100,100,100,100};

            s_GameClear.loop_count = 1;
            s_GameClear.interval = 0.05f;
            for(auto i= 0;i<arraysize;++i)
            {
                s_GameClear.set_next_tone(array[i]);
                s_GameClear.set_next_tone(array[i]+20);
            }
            // s_GameClear.set_next_tone(0);
            // s_GameClear.set_next_tone(0);
            // for(auto i=0;i<15;++i)
            // {
            //     s_GameClear.set_next_tone(50+i*10);
            //     s_GameClear.set_next_tone(100+i*10);
            // }

            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(0);
            // s_GameClear.set_next_tone(0);
            // s_GameClear.set_next_tone(0);
            // s_GameClear.set_next_tone(0);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(0);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
            // s_GameClear.set_next_tone(100);
            // s_GameClear.set_next_tone(240);
        }
    }

    SoundData GetSound(SoundEnum soundName)
    {
        switch(soundName)
        {
            case SoundEnum::GameClear: return s_GameClear;

            case SoundEnum::Low: return s_Low;
            case SoundEnum::Middle: return s_Middle;
            case SoundEnum::High: return s_High;

            case SoundEnum::OK: return s_OK;
            case SoundEnum::Succsess: return s_Succsess;
            case SoundEnum::Misstake: return s_Misstake;

            default : return s_OK;
        }

        return s_OK;
    }
}