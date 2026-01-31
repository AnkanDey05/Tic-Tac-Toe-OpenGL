#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main(){
    if (!glfwInit())
    {
        std::cout<<"GLFW failed to initialize\n";
        glfwTerminate();
    }
    else{
        std::cout<<"GLFW Initialized succesfully\n";
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    GLFWwindow* GameWindow = glfwCreateWindow(800,600,"Fuck CMake",NULL,NULL);

    if (!GameWindow)
    {
        std::cerr<<"Window creation failed\n";
        glfwTerminate();
    }

    glfwMakeContextCurrent(GameWindow);
    
    if (glewInit()!= GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    int bufferwidth, bufferheight;

    glfwGetFramebufferSize(GameWindow,&bufferwidth,&bufferheight);

    glViewport(0,0,bufferwidth,bufferwidth);

    while (!glfwWindowShouldClose(GameWindow))
    {
        glfwPollEvents();

        glClearColor(0.5,0.5,0.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(GameWindow);
    }

    return 0;
    
    


    
}