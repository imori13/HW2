#include <Arduino.h>
#include <pinout.h>

#include "System/Timer.h"
#include "System/Input.h"
#include "Game/Scene/GameScene.h"
#include "Game/GameSound.h"

namespace
{
    constexpr uint8_t BUTTON_COUNT = 3u;
}

void setup() {
    Serial.begin(115200);

    // initialize input
    Input::Initialize(BUTTON_COUNT);
    Input::AddButton(Pinout::D2);
    Input::AddButton(Pinout::D4);
    Input::AddButton(Pinout::D6_PWM_READY);

    // initialize sound
    GameSound::Initialize(Pinout::A2);

    // initialize game
    GameScene::Initialize();
}

void loop() {
    // update device
    Timer::Update();
    Input::Update();
    GameSound::Update();

    // update scene
    GameScene::Update();
}
