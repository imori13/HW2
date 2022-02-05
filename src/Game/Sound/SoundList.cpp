#include "SoundList.h"
#include "System/Debug.h"

namespace
{
    SoundData s_Low;
    SoundData s_Middle;
    SoundData s_High;

    SoundData s_OK;
    SoundData s_NO;
    SoundData s_Succsess;
    SoundData s_Misstake;

    SoundData s_GameClear;
}

namespace SoundList
{
    void Initialize()
    {
        Debug::LogLine("create gamesound.");

        // gamesounds.
        {
            constexpr uint8_t loopCount = 1;
            constexpr float gamesound_interval = 0.001f;

            constexpr int arraysize = 7;
            constexpr uint8_t array[arraysize] = {80,110,85,105,90,100,95};

            s_Low.Create(arraysize*2,loopCount,gamesound_interval);
            s_Middle.Create(arraysize*2,loopCount,gamesound_interval);
            s_High.Create(arraysize*2,loopCount,gamesound_interval);

            for(auto i= 0;i<arraysize;++i)
            {
                s_Low.SetNext(array[i]+20);
                s_Low.SetNext(array[i]-20);
                s_Middle.SetNext(array[i]+40);
                s_Middle.SetNext(array[i]+50);
                s_High.SetNext(array[i]+100);
                s_High.SetNext(array[i]+120);
            }
        }

        Debug::LogLine("create ok sound.");

        // OK
        {
            s_OK.Create(6,1,0.05f);
            s_OK.SetNext(50);
            s_OK.SetNext(0);
            s_OK.SetNext(100);
            s_OK.SetNext(150);
            s_OK.SetNext(0);
            s_OK.SetNext(200);
        }

        // NO
        {
            s_NO.Create(6,1,0.05f);
            s_NO.SetNext(200);
            s_NO.SetNext(0);
            s_NO.SetNext(150);
            s_NO.SetNext(100);
            s_NO.SetNext(0);
            s_NO.SetNext(50);
        }

        Debug::LogLine("create succsess sound.");

        // Succsess
        {
            s_Succsess.Create(64,1,0.05f);
            for(auto i=0;i<3;++i)
            {
                for(auto j=0;j<5;++j)
                {
                    s_Succsess.SetNext(100+(i*10)+(j*10));
                }
            }
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
            s_Succsess.SetNext(100);
            s_Succsess.SetNext(240);
        }

        Debug::LogLine("create misstake sound.");

        // Misstake
        {
            s_Misstake.Create(58,1,0.025f);
            s_Misstake.SetNext(200);
            s_Misstake.SetNext(0);
            s_Misstake.SetNext(100);
            s_Misstake.SetNext(200);
            s_Misstake.SetNext(0);
            s_Misstake.SetNext(100);
            s_Misstake.SetNext(200);
            s_Misstake.SetNext(0);
            s_Misstake.SetNext(100);
            s_Misstake.SetNext(200);
            s_Misstake.SetNext(0);
            s_Misstake.SetNext(100);
            for(auto i=2;i>=0;--i)
            {
                for(auto j=3;j>=0;--j)
                {
                    s_Misstake.SetNext(50+(i*5)+(j*5));
                    s_Misstake.SetNext(100+(i*5)+(j*5));
                }
            }
            for(auto i=10;i>=0;--i)
            {
                s_Misstake.SetNext(0+i*5);
                s_Misstake.SetNext(50+i*5);
            }
        }

        Debug::LogLine("create clear sound.");

        // clear
        {
            constexpr int arraysize = 32;
            constexpr uint8_t array[arraysize] = {100,0,100,0,100,0,100,100,100,0,80,80,80,80,90,90,90,90,100,100,0,0,90,0,100,100,100,100,100,100,100,100};

            s_GameClear.Create(128,1,0.05f);
            for(auto i= 0;i<arraysize;++i)
            {
                s_GameClear.SetNext(array[i]);
                s_GameClear.SetNext(array[i]+20);
            }
            s_GameClear.SetNext(0);
            s_GameClear.SetNext(0);
            for(auto i=0;i<15;++i)
            {
                s_GameClear.SetNext(50+i*10);
                s_GameClear.SetNext(100+i*10);
            }

            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(0);
            s_GameClear.SetNext(0);
            s_GameClear.SetNext(0);
            s_GameClear.SetNext(0);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(0);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
            s_GameClear.SetNext(100);
            s_GameClear.SetNext(240);
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
            case SoundEnum::NO: return s_NO;

            case SoundEnum::Succsess: return s_Succsess;
            case SoundEnum::Misstake: return s_Misstake;

            default : return s_OK;
        }

        return s_OK;
    }
}