#pragma once
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
private:
    int ID;
public:
    Shader()= default;
    ~Shader()=default;

    // Functions 

    void compilefromSource(const char* vertex_shader_path, const char* fragment_shader_path);
    int getID();
};
