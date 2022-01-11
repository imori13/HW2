#pragma once
#include "Device.h"

class Speaker;
class SpeakerWrapp
{
public:
    SpeakerWrapp(uint8_t pin);
protected:
    Speaker* m_pSpeaker;
};