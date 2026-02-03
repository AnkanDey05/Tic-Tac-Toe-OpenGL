#include "../../include/core/Application.hpp"

Application::Application():gamewindow(800,600,"TicTacToe"){
    
}
Application::~Application(){

}
void Application::run() {

    gamewindow.makeContextCurrent();
    
    renderer.init(gamewindow.getbufferwidth(),gamewindow.getbufferheight());
    renderer.updateViewport(gamewindow.getbufferwidth(),gamewindow.getbufferheight());


    Quad test(100,110, 150,150, Color::Cyan);
    Mesh testmesh(test.getVertices(),test.getIndices());

    glm::vec3 color (0.1f,0.4f,0.5f);

    while (!gamewindow.shouldClose())
    {
        gamewindow.handelEvents();
        renderer.clearColor(Color::ForestGreen);

        testmesh.bind();
        renderer.setFvec3("u_Color", test.color.get_r(),test.color.get_g(),test.color.get_b());
        renderer.draw(testmesh);

        gamewindow.swapbuffers();
    }
    
}