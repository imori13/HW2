#include "SoundData.h"
#include "System/Debug.h"

// default setting
namespace
{
    constexpr uint8_t default_loop_count = 1;
    constexpr float default_interval = 0.1f;
}

// local method
namespace
{
    void ErrorLog_AndSkip()
    {
        Debug::LogLine("over limit to sound data."); 
    }

    void NextIndex(uint8_t* head)
    {
        if(*head < SOUND_ARRAY_MAX)
        {
            ++(*head);
            return;
        }
        
        ErrorLog_AndSkip();
    }
}

SoundData::SoundData()
    : m_data_empty_index(0)
    , loop_count(default_loop_count)
    , interval(default_interval)
{} 

void SoundData::set_next_tone(uint8_t tone)
{
    // set data.
    m_data_array[m_data_empty_index] = tone;

    // set next index.
    NextIndex(&m_data_empty_index);
}

const uint8_t& SoundData::at(uint8_t index) const
{
    return m_data_array[index];
}


const uint8_t& SoundData::size() const
{
    return m_data_empty_index;  // is data size
}