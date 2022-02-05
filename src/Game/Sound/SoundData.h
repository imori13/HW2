#pragma once
#include <stdint.h>

class SoundData
{
public:
    void Create(uint8_t count,uint8_t loopCount,float interval);
    void SetNext(uint8_t tone);

// getter
public:
    const uint8_t& at(uint8_t index) const;
    const uint8_t& size() const;

    const uint8_t& GetLoopCount() const { return m_LoopCount; }
    const float& GetInterval() const { return m_Interval; } 

// private value
private:
    uint8_t* m_Data;
    uint8_t m_DataCount;
    uint8_t m_LoopCount;
    float m_Interval;
    
private:
    uint8_t m_EmptyHeader;
};