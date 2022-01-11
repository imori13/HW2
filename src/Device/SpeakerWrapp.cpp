#include "SpeakerWrapp.h"

#include <speaker.h>

SpeakerWrapp::SpeakerWrapp(uint8_t pin)
    : m_pSpeaker(nullptr)
{
    m_pSpeaker = new Speaker(Pinout::D6_PWM_READY);
}