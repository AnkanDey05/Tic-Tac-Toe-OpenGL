#pragma once

class Color
{
    
    float r;
    float g;
    float b;
    float a;
    
    
    constexpr Color(float r,float g,float b,float a = 1.0f): r(r),g(g),b(b),a(a){};

public:
 
// Predefined Colors:

    static const Color Red;
    static const Color Blue;
    static const Color Green;
    static const Color Black;
    static const Color Grey;
    static const Color Dark_Grey;
    static const Color Background;
    static const Color White;

    constexpr float get_r() const { return r; }
    constexpr float get_g() const { return g; }
    constexpr float get_b() const { return b; }
    constexpr float get_a() const { return a; }
    static constexpr Color FromRGB(int r, int g, int b, int a = 255)
    {
        return Color(
            r / 255.0f,
            g / 255.0f,
            b / 255.0f,
            a / 255.0f
        );
    }

};
