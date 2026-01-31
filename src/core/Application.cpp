#include "../../include/core/Application.hpp"

Application::Application():gamewindow(800,600,"TicTacToe"){
    
}
Application::~Application(){

}
void Application::run() {

    gamewindow.makeContextCurrent();
    
    renderer.init();
    renderer.updateViewport(gamewindow.getbufferwidth(),gamewindow.getbufferheight());

    while (!gamewindow.shouldClose())
    {
        gamewindow.handelEvents();
        renderer.clearColor(Color::FromRGB(20,51,120));
        gamewindow.swapbuffers();
    }
    
}