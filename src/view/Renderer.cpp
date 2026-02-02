#include <GL/glew.h>
#include "../../include/view/Renderer.hpp"
#include <stdexcept>

void Renderer::init(int width, int height){

    glewExperimental= GL_TRUE;

    if (glewInit()!= GLEW_OK)
    {
        throw std::runtime_error("[Error]: Glew failed To initialize");
    }
    used_shader.compilefromSource("../../assets/Shaders/vShader.glsl","../../assets/Shaders/fShader.glsl");
    projection = glm::ortho(
        0.0f,
        (float)width,
        (float)height,
        0.0f
    );
    

}

void Renderer::updateViewport(int width, int height){

    glViewport(0,0,width,height);
}
void Renderer::clearColor(const Color& color){

    glClearColor(color.get_r(), color.get_g(), color.get_b(), color.get_a());
    glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::endframe(){

}