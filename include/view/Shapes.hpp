#pragma once
#include <vector>
#include "Color.hpp"

struct Vertex2D {
    float x;
    float y;
};

class Quad {
private:
    int x, y;
    int width, height;

    std::vector<Vertex2D> vertices;
    std::vector<unsigned int> indices;

    Color color = Color::White;

public:
    Quad(int x, int y, int width, int height, Color color = Color::White)
        : x(x), y(y), width(width), height(height), color(color)
    {
        float xf = static_cast<float>(x);
        float yf = static_cast<float>(y);
        float wf = static_cast<float>(width);
        float hf = static_cast<float>(height);

        vertices = {
            {xf,       yf},        // Top-left
            {xf + wf,  yf},        // Top-right
            {xf + wf,  yf + hf},   // Bottom-right
            {xf,       yf + hf}    // Bottom-left
        };

        indices = {
            0, 1, 2,
            2, 3, 0
        };
    }

    const std::vector<Vertex2D>& getVertices() const { return vertices; }
    const std::vector<unsigned int>& getIndices() const { return indices; }
    const Color& getColor() const { return color; }
};
