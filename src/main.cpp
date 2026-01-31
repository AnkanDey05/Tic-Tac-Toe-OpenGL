#include <GL/glew.h>
#include "../include/core/Window.hpp"

int main(){

    Window game(800,600,"TicTacToe");

    glViewport(0,0, game.getbufferwidth(), game.getbufferheight());

    while (!game.shouldClose())
    {
        game.handelEvents();
        glClearColor(0.5,0.5,0.5,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        game.swapbuffers();
    }
    


}
