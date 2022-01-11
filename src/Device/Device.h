#pragma once
#include <gpio.h>
#include <stdint.h>
#include <pinout.h>

class Device
{
public:
    Device();
    virtual ~Device();
protected:
    Gpio* m_pGpio;
};