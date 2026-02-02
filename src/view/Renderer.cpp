#include <GL/glew.h>
#include "../../include/view/Renderer.hpp"
#include <iostream>
#include <stdexcept>

void Renderer::init(int width, int height)
{

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("[Error]: Glew failed To initialize");
    }
    used_shader.compilefromSource("../assets/Shaders/vShader.glsl", "../assets/Shaders/fShader.glsl");
    projection = glm::ortho(
        0.0f,
        (float)width,
        (float)height,
        0.0f);

    // Make sure the shader is active and upload the projection matrix uniform.
    glUseProgram(used_shader.getID());
}

void Renderer::updateViewport(int width, int height)
{

    glViewport(0, 0, width, height);

    // Recalculate projection and upload to shader so resizing keeps coordinates correct
    projection = glm::ortho(
        0.0f,
        (float)width,
        (float)height,
        0.0f);

    // If the shader is valid, set the uniform
    glUseProgram(used_shader.getID());
    int loc = glGetUniformLocation(used_shader.getID(), "uProjection");
    if (loc == -1) {
        std::cerr << "[Warning]: uniform 'uProjection' not found in shader (updateViewport)\n";
    } else {
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(projection));
    }
}
void Renderer::clearColor(const Color &color)
{

    glClearColor(color.get_r(), color.get_g(), color.get_b(), color.get_a());
    glClear(GL_COLOR_BUFFER_BIT);
}
void Renderer::draw(Mesh &mesh)
{

    mesh.bind();

    glDrawElements(GL_TRIANGLES, mesh.getindexCount(), GL_UNSIGNED_INT, NULL);
}

void Renderer::activateShader()
{

    glUseProgram(used_shader.getID());
}
void Renderer::setFvec3(const std::string& name, float value1, float value2, float value3) const
{
    int pos = glGetUniformLocation(const_cast<Shader&>(used_shader).getID(), name.c_str());
    if (pos==-1)
    {
        std::cerr << "[Error}: Could not found the unifom\n";
    }
    else
    {

    glUniform4f(pos, value1, value2, value3, 1.0f);
    }
}