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

    constexpr inline static Color Black() { return Color(0, 0, 0); }
    constexpr inline static Color White() { return Color(200, 200, 200); }
    constexpr inline static Color Red() { return Color(255, 0, 0); }
    constexpr inline static Color Green() { return Color(0, 229, 0); }
    constexpr inline static Color Blue() { return Color(2, 183, 236); }
    constexpr inline static Color Yellow() { return Color(255, 230, 0); }
};