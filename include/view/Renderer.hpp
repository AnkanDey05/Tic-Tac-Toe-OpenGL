#pragma once
#include <GL/glew.h>
#include "Color.hpp"

class Renderer
{
private:
    /* data */
public:
    Renderer()=default;
    ~Renderer() = default;
    void init();
    void updateViewport(int width, int height);
    void clearColor(const Color& color);
    void endframe();
};

