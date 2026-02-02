#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Color.hpp"
#include "Shader.hpp"
class Renderer
{
private:
    unsigned int VAO,VBO;
    Shader used_shader;
    glm::mat4 projection;

public:
    Renderer()=default;
    ~Renderer() = default;
    void init(int width, int height);
    void updateViewport(int width, int height);
    void clearColor(const Color& color);
    void endframe();
};

