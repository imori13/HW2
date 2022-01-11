#include "Device.h"

Device::~Device()
{
    delete m_pGpio;
}