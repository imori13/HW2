#pragma once
#include <stdint.h>

struct Color
{
public:
    uint8_t r,g,b;

public:
    constexpr Color(float r, float g,float b)
        : r(r), g(g), b(b)
    {

    }

    constexpr inline static Color Red() { return Color(255,0,0); }
    constexpr inline static Color Green() { return Color(0,255,0); }
    constexpr inline static Color Blue() { return Color(0,0,255); }
    constexpr inline static Color Black() { return Color(0,0,0); }
};