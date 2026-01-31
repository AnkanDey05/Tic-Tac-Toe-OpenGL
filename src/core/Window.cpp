 #include "../../include/core/Window.hpp"
#include <stdexcept>
#include <iostream>

Window::Window(int width, int height, const char* title){

    if (!glfwInit())
    {
        glfwTerminate();
        throw std::runtime_error("Failed to init GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);


    window = glfwCreateWindow(width,height,title,NULL,NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Window Creation Failed");
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window,this);
    glfwGetFramebufferSize(window,&framebufferwidth,&framebufferheight);
    glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);
}

Window::~Window(){
    
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::framebufferSizeCallback(GLFWwindow* window, int w, int h ){

    auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (!self)
    {
        return;
    }
    self->framebufferwidth = w;
    self->framebufferheight = h;
    std::cout<<"Frame buffer Modified\n";
    
}
int Window::getbufferwidth()const{

    return framebufferwidth;
}
int Window::getbufferheight()const{

    return framebufferheight;
}
void Window::swapbuffers(){
    
    glfwSwapBuffers(window);

}
void Window::handelEvents(){

    glfwPollEvents();

}
bool Window::shouldClose()const{

    return glfwWindowShouldClose(window);
};