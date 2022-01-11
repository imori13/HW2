#include <Arduino.h>
#include <pinout.h>

#include "Device/Timer.h"
#include "Device/Input.h"
#include "GameLogic/GameScene.h"

void setup() {
    Serial.begin(115200);

    GameScene::Initialize();
}

void loop() {
    Timer::Update();
    Input::Update();
    GameScene::Update();
}
