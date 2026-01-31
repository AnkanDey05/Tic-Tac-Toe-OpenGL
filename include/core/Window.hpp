#pragma once
#include <GLFW/glfw3.h>
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
    int getbufferwidth() const;
    int getbufferheight() const;
    static void framebufferSizeCallback(GLFWwindow* window, int w, int h);
};

