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
    void set1i(int value, const char* name ){

        glUniform1i(glGetUniformLocation(ID,name),value);
    }
};
