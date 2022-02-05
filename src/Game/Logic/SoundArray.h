#pragma once
#include "GameLogic.h"
#include "System/Debug.h"
#include <stdint.h>

enum class SoundInterval
{
    Low,
    Middle,
    High,
};

// 1レベル単位で再生する音階データを記録しておくもの
struct SoundArray
{
public:
    ~SoundArray()
    {
        clear();
    }

    void Create(uint8_t count)
    {
        this->count = count;
        soundArray = new SoundInterval[count];
    }

    SoundInterval& at(uint8_t index)
    {
        if(index < 0 || index >= count)
        {
            Debug::LogLine("index error in /gamemanager.cpp/soundarray/at()");
        }

        return soundArray[index];
    }

    const SoundInterval& at(uint8_t index) const
    {
        if(index < 0 || index >= count)
        {
            Debug::LogLine("index error in /gamemanager.cpp/soundarray/at()");
        }

        return soundArray[index];
    }

    uint8_t size() const
    {
        return count;
    }

    void clear()
    {
        if(soundArray != nullptr)
        {
            delete[] soundArray;
        }
    }

private:
    SoundInterval* soundArray;
    uint8_t count;
};