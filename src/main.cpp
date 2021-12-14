#include <Arduino.h>
#include <pinout.h>

#include "Timer.h"
#include "Input.h"
#include "GameScene.h"

void setup() {
    Serial.begin(115200);

    GameScene::Initialize();
}

void loop() {
    Timer::Update();
    Input::Update();
    GameScene::Update();
}
