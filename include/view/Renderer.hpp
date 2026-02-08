#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Color.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
class Renderer
{
private:
    unsigned int VAO, VBO;
    glm::mat4 projection;

public:
    Shader used_shader;
    Renderer() = default;
    ~Renderer() = default;
    void init(int width, int height);
    void updateViewport(int width, int height);
    void clearColor(const Color &color);
    void draw(Mesh &mesh);
    void activateShader();
    void setFvec3(const std::string &name, float value1, float value2, float value3) const;
};
