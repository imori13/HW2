#pragma once

#include <pinout.h>
#include <Arduino.h>

namespace Debug{

template <typename T>
  void Print(T msg){
    Serial.println(msg);
  }
}
