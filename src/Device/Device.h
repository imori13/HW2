#pragma once
#include <gpio.h>
#include <stdint.h>

class Device
{
public:
    virtual ~Device();
protected:
    Gpio* m_pGpio;
};