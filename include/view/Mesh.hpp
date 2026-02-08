#pragma once 
#include <GL/glew.h>
#include "Shapes.hpp"
class Mesh
{
private:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    unsigned int indexCount;
public:
    Mesh(const std::vector<Vertex2D> &vertecies, const std::vector<unsigned int> &indicies){

        indexCount= indicies.size();

        // Generating Buffers: 

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1,&VBO);
        glGenBuffers(1,&EBO);

        // Binding the Buffers: 

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);

        glBufferData(GL_ARRAY_BUFFER, vertecies.size()* sizeof(Vertex2D), vertecies.data(),GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size()*sizeof(unsigned int), indicies.data(), GL_STATIC_DRAW);

        // Setting Up Vertex Attribute Array 

        glEnableVertexAttribArray(0);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)0);
        // UV attribute
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)(2 * sizeof(float)));
         
        // unbinding the vertex array 

        glBindVertexArray(0);



    }
    ~Mesh(){

        glDeleteVertexArrays(1,&VAO);
        glDeleteBuffers(1,&VBO);
        glDeleteBuffers(1,&EBO);

    };

    void bind(){

        glBindVertexArray(VAO);

    }

    unsigned int getindexCount(){

        return indexCount;
    }

};

