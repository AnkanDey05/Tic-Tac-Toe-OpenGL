#include <GL/glew.h>
#include "../../include/core/Application.hpp"

Application::Application():gamewindow(800,600,"TicTacToe"){
    
}
Application::~Application(){

}
void Application::run() {

    gamewindow.makeContextCurrent();
    if (glewInit()!= GLEW_OK)
    {
        throw std::runtime_error("Failed to init GLEW");
    }
    
    while (!gamewindow.shouldClose())
    {
        gamewindow.handelEvents();
        glClearColor(0.2,0.3,0.4,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        gamewindow.swapbuffers();
    }
    
}