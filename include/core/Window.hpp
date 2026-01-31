#pragma once
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
class Window
{
private:
   int framebufferwidth;
   int framebufferheight;
public:
    Window(int width, int height, const char* title);
    ~Window();
    GLFWwindow* window ;
    bool shouldClose() const;
    void handelEvents();
    void swapbuffers();
    void makeContextCurrent()const;
    int getbufferwidth() const;
    int getbufferheight() const;
    static void framebufferSizeCallback(GLFWwindow* window, int w, int h);
};

