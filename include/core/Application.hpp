#pragma once
#include "../view/Renderer.hpp"
#include "../view/Shapes.hpp"
#include "../view/Mesh.hpp"
#include "Window.hpp"
class Application
{
private:
    Window gamewindow;
    Renderer renderer;
    void processinput();
    void update(); 

public:
    Application();
    ~Application();
    void run();
};


