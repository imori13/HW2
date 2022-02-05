#include "SoundData.h"
#include "System/Debug.h"

void SoundData::Create(uint8_t count,uint8_t loopCount,float interval)
{
    m_EmptyHeader = 0;

    this->m_DataCount = count;
    this->m_LoopCount = loopCount;
    this->m_Interval = interval;

    m_Data = new uint8_t[count];
}

void SoundData::SetNext(uint8_t tone)
{
    m_Data[m_EmptyHeader] = tone;
    
    if(m_EmptyHeader < m_DataCount)
    {
        ++m_EmptyHeader;
    }
    else
    {
        Debug::LogLine("outofrange error in SoundData.cpp/SetNext()");
    }
}

const uint8_t& SoundData::at(uint8_t index) const
{
    if(index < 0 || index >= m_DataCount)
    {
        Debug::LogLine("outofrange error in SoundData.cpp/at()");
    }

    return m_Data[index];
}


const uint8_t& SoundData::size() const
{
    return m_DataCount;  // is data size
}