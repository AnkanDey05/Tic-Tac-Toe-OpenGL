#include "../../include/core/Application.hpp"

Application::Application():gamewindow(800,600,"TicTacToe"){
    
}
Application::~Application(){

}
void Application::run() {

    gamewindow.makeContextCurrent();
    
    renderer.init(gamewindow.getbufferwidth(),gamewindow.getbufferheight());
    renderer.updateViewport(gamewindow.getbufferwidth(),gamewindow.getbufferheight());


    Quad test(100,110, 450,450, Color::Cyan);
    Mesh testmesh(test.getVertices(),test.getIndices());

    Texture tex;
    if (!tex.loadFromFile("../assets/Textures/awesomeface.png")) {
        std::cerr << "[Error]: Failed to load texture\n";
    }

    test.setTexture(tex);
    test.setRendermode(renderMode::textureOnly);


    renderer.activateShader();
    renderer.used_shader.set1i(0, "u_Texture"); // texture unit 0
    renderer.used_shader.set1i(tex.isValid() ? 1 : 0, "u_UseTexture");



    while (!gamewindow.shouldClose())
    {
        gamewindow.handelEvents();
        renderer.clearColor(Color::ForestGreen);


        if (test.quadTexture && test.quadTexture->isValid()) {
            test.quadTexture->bind(0);
        }

        testmesh.bind();
        renderer.setFvec3("u_Color", test.color.get_r(),test.color.get_g(),test.color.get_b());
        renderer.draw(testmesh);

        gamewindow.swapbuffers();
    }
    
}