#include "Input.h"
#include "Button.h"
#include "Debug.h"

namespace
{
    Button** s_ButtonArray;
    uint8_t s_Count;
    uint8_t s_CurrentHead;
}

namespace Input
{
    void CheckIndex(uint8_t checkIndex);

    void Initialize(uint8_t buttonLimit)
    {
        s_ButtonArray = new Button* [buttonLimit];
        s_Count = buttonLimit;
    }

    void AddButton(uint8_t pin)
    {
        CheckIndex(s_CurrentHead);

        s_ButtonArray[s_CurrentHead] = new Button(pin);
        ++s_CurrentHead;
    }

    void Update()
    {
        for(auto i = 0u; i < s_CurrentHead; ++i)
        {
            s_ButtonArray[i]->Update();
        }
    }

    bool GetDown(uint8_t index)
    {
        CheckIndex(index);

        return s_ButtonArray[index]->ButtonDown();
    }

    bool GetHold(uint8_t index)
    {
        CheckIndex(index);

        return s_ButtonArray[index]->ButtonHold();
    }

    bool GetUp(uint8_t index)
    {
        CheckIndex(index);

        return s_ButtonArray[index]->ButtonUp();
    }

    void CheckIndex(uint8_t checkIndex)
    {
        if(checkIndex < 0 || checkIndex > s_Count)
        {
            Debug::Log("Input.cpp 異常値の検出=>");
            Debug::LogLine(checkIndex);
        }
    }
}