#pragma once

#include <stdint.h>

constexpr uint8_t SOUND_ARRAY_MAX = 64u;

struct SoundData
{
public:
    // SoundData();

// setter
public:
    void set_next_tone(uint8_t tone);

// getter
public:
    const uint8_t& at(uint8_t index) const;
    const uint8_t& size() const;

// public value    
public:
    uint8_t loop_count;
    float interval;

// private value
private:
    uint8_t m_data_array[SOUND_ARRAY_MAX];
    uint8_t m_data_empty_index;  // is data next empty index header.
};