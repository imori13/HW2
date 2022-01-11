#include "GameScene.h"
#include "Device/LED.h"
#include "Device/Input.h"
#include "Device/Debug.h"
#include <pinout.h>

#define BUTTON_COUNT 3

namespace {
    LED baseLED(Pinout::LED);
    LED moduleLED(Pinout::A0);
}

namespace GameScene
{
    void Initialize()
    {
        Input::Initialize(BUTTON_COUNT);
        Input::AddButton(Pinout::D2);
        Input::AddButton(Pinout::D4);
        Input::AddButton(Pinout::D6_PWM_READY);
    }

    void Update()
    {
        baseLED.BlinkUpdate(0.1f);
        moduleLED.BlinkUpdate(0.1f);

        for(auto i=0u;i<BUTTON_COUNT;++i){
            if(Input::ButtonUp(i))
            {
                Debug::Log("Button Pushed : ");
                Debug::LogLine(i);
            }
        }
    }
}
