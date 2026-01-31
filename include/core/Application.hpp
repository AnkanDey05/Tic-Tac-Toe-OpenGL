#pragma once
#include "Window.hpp"

class Application
{
private:
    Window gamewindow;
    // void processinput();
    // void update(); 

public:
    Application();
    ~Application();
    void run();
};


