 #include "../../include/core/Window.hpp"

Window::Window(int width, int height, const char* title){

    if (!glfwInit())
    {
        glfwTerminate();
        throw std::runtime_error("Failed to init GLFW");
    }
    
    // Version and OpenGL Profile: 

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);

    //Window

    window = glfwCreateWindow(width,height,title,NULL,NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Window Creation Failed");
    }

    glfwSetWindowUserPointer(window,this); //This stores the current window object to a pointer
    glfwGetFramebufferSize(window,&framebufferwidth,&framebufferheight);
    glfwSetFramebufferSizeCallback(window,framebufferSizeCallback);
}

Window::~Window(){
    
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::framebufferSizeCallback(GLFWwindow* window, int w, int h ){
    
    //assigning the previously stored pointer to self
    /* 
    because glfw is written in c language the window object cannot hold a function 
    so to get the window object we are working on we have to pass that through a pointer and reassign them to a variable,
    in this case self, only after that we can use it to modify or in this case get the buffersize
    */

    auto* self = static_cast<Window*>(glfwGetWindowUserPointer(window)); 
    if (!self)
    {
        return;
    }
    self->framebufferwidth = w;
    self->framebufferheight = h;
    std::cout<<"Frame buffer Modified\n";
    
}
void Window::makeContextCurrent()const{

    glfwMakeContextCurrent(window);
}
int Window::getbufferwidth()const{

    return framebufferwidth;
}
int Window::getbufferheight()const{

    return framebufferheight;
}
void Window::swapbuffers(){
    
    glfwSwapBuffers(window);

}
void Window::handelEvents(){

    glfwPollEvents();

}
bool Window::shouldClose()const{

    return glfwWindowShouldClose(window);
};