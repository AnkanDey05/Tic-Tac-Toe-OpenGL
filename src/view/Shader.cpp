#include "../../include/view/Shader.hpp"

void Shader::compilefromSource(const char* vertex_shader_path, const char* fragment_shader_path){


    const char* vertex_shader_code;
    const char* fragment_shader_code;
    std::ifstream vertex_shader_file;
    std::ifstream fragment_shader_file;

    // Making Sure that our program can throw exception 

    	vertex_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fragment_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // Opening The file 

    try
    {
        vertex_shader_file.open(vertex_shader_path);
        fragment_shader_file.open(fragment_shader_path);
        std::stringstream vshaderstream, fshaderstream;

        // movinf the content to stream 

        vshaderstream << vertex_shader_file.rdbuf();
        fshaderstream << fragment_shader_file.rdbuf();

        // Closing already opened files:

        vertex_shader_file.close();
        fragment_shader_file.close();

        // Converting it to a str

        vertex_shader_code = vshaderstream.str().c_str();
        fragment_shader_code = fshaderstream.str().c_str();

    }
    catch(const std::exception& e)
    {
        std::cerr<<"[Error]: Unable to load Shaderfile \n";
        std::cerr << e.what() << '\n';
    }
    
    int sucess;
    char infolog[512];
    unsigned int vshader,fshader;

    // creating and compiling vertex shader

    vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader,1, &vertex_shader_code,NULL);
    glCompileShader(vshader);

    // Checking for errors 

    glGetShaderiv(vshader,GL_COMPILE_STATUS, &sucess);

    if (!sucess)
    {
        glGetShaderInfoLog(vshader,512,NULL, infolog);
        std::cerr<<"[Error]: Shader Compilation Failed\n";
        std::cerr<<infolog<<"\n";
    }
    


    // creating and compiling fragment shader 

    fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader,1,&fragment_shader_code,NULL);
    glCompileShader(fshader);

    //Checking for error 

    glGetShaderiv(fshader,GL_COMPILE_STATUS, &sucess);

    if (!sucess)
    {
        glGetShaderInfoLog(fshader,512,NULL, infolog);
        std::cerr<<"[Error]: Shader Compilation Failed\n";
        std::cerr<<infolog<<"\n";
    }

    // Linking shader 

    ID=glCreateProgram();
    glAttachShader(ID, vshader);
    glAttachShader(ID,fshader);
    glLinkProgram(ID);

    // Checkinh for linking errors 

    glGetProgramiv(ID,GL_LINK_STATUS, &sucess);

    if (!sucess)
    {
        glGetProgramInfoLog(ID,512,NULL, infolog);
        std::cerr<<"[Error]: Shader Linking Failed\n";
        std::cerr<<infolog<<"\n";
    }

    // Deleting left shaders 

    glDeleteShader(vshader);
    glDeleteShader(fshader);

}

void Shader::use(){

    glUseProgram(ID);
    
}