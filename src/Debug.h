#pragma once

#include <pinout.h>
#include <Arduino.h>

namespace Debug{

template <typename T>
  void Log(T msg){
    Serial.print(msg);
  }
  
template <typename T>
  void LogLine(T msg){
    Serial.println(msg);
  }
}
