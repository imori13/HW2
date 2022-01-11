#include "Device.h"

Device::Device()
    : m_pGpio(nullptr)
{

}

Device::~Device()
{
    delete m_pGpio;
}