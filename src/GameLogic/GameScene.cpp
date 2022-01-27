#include "GameScene.h"
#include "GameSound.h"
#include "Device/LED.h"
#include "System/Input.h"
#include "System/Debug.h"

namespace 
{
    LED baseLED(Pinout::LED);
    LED moduleLED(Pinout::A0);
}

namespace GameScene
{
    GameState g_GameState = GameState::StandBy;

    void Initialize()
    {
        
    }

    void Update()
    {
        baseLED.BlinkUpdate(0.1f);
        moduleLED.BlinkUpdate(0.1f);

        for(auto i=0u; i<Input::size(); ++i)
        {
            if(Input::ButtonUp(i))
            {
                Debug::Log("Button Pushed : ");
                Debug::LogLine(i);
            }

            if(Input::ButtonUp(0))
            {
                GameSound::OnPlay(SoundEnum::Test);
            }

            if(Input::ButtonUp(1))
            {
                GameSound::OnPlay(SoundEnum::GameClear);
            }

            if(Input::ButtonUp(2))
            {
                GameSound::OnPlay(SoundEnum::GameOver);
            }
        }
    }
}
