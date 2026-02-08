#pragma once
#include <vector>
#include "Color.hpp"
#include "Texture.hpp"
struct Vertex2D
{
    float x;
    float y;
    float u;
    float v;
};

enum class renderMode
{

    colorOnly,
    textureOnly,
    texturedColor

};
class Quad
{
private:
    int x, y;
    int width, height;
    std::vector<Vertex2D> vertices;
    std::vector<unsigned int> indices;

public:
    Color color = Color::White;
    renderMode Mode = renderMode::colorOnly;
    Texture* quadTexture = nullptr;
    Quad(int x, int y, int width, int height, Color color = Color::White)
        : x(x), y(y), width(width), height(height), color(color)
    {
        float xf = static_cast<float>(x);
        float yf = static_cast<float>(y);
        float wf = static_cast<float>(width);
        float hf = static_cast<float>(height);

        vertices = {
            {xf,     yf,     0.0f, 0.0f},
            {xf+wf,  yf,     1.0f, 0.0f},
            {xf+wf,  yf+hf,  1.0f, 1.0f},
            {xf,     yf+hf,  0.0f, 1.0f}
        };

        indices = {
            0, 1, 2,
            2, 3, 0};
    }

    const std::vector<Vertex2D> &getVertices() const { return vertices; }
    const std::vector<unsigned int> &getIndices() const { return indices; }
    const Color &getColor() const { return color; }
    void setColor(Color &_color)
    {

        color = _color;
    }
    void setTexture(Texture& texture){

        if (texture.isValid())
        {
            
            quadTexture= &texture;
            Mode  = renderMode::texturedColor;
        }
        else{

            std::cerr<<"[Error::Shape::Quad]: Texture is not valid\n";
        }
        
    }
    void setRendermode(renderMode mode){

        Mode = mode;

    }
};
