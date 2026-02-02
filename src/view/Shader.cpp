#include "../../include/view/Shader.hpp"
#include <filesystem>

void Shader::compilefromSource(const char *vertex_shader_path, const char *fragment_shader_path)
{

    std::string vertex_shader_source;
    std::string fragment_shader_source;
    const char *vertex_shader_code;
    const char *fragment_shader_code;
    std::ifstream vertex_shader_file;
    std::ifstream fragment_shader_file;

    // Making Sure that our program can throw exception

    vertex_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragment_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // Checking If the directory exists

    if (!std::filesystem::exists(vertex_shader_path))
    {
        std::cerr << "[Error]: Vertex shader path does not exist: "
                  << vertex_shader_path << "\n";
        std::cerr << "Current working directory: "
                  << std::filesystem::current_path() << "\n";
        std::cerr << "Terminating Shader Compilation...\n";
        return;
    }

    if (!std::filesystem::exists(fragment_shader_path))
    {
        std::cerr << "[Error]: Vertex shader path does not exist: "
                  << fragment_shader_path << "\n";
        std::cerr << "Current working directory: "
                  << std::filesystem::current_path() << "\n";
        std::cerr << "Terminating Shader Compilation...\n";
        return;
    }

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

        vertex_shader_source = vshaderstream.str();
        fragment_shader_source = fshaderstream.str();

        vertex_shader_code = vertex_shader_source.c_str();
        fragment_shader_code = fragment_shader_source.c_str();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Error]: Unable to load Shader file\n";
        std::cerr << e.what() << "\n";
        return;
    }

    int sucess;
    char infolog[512];
    unsigned int vshader, fshader;

    // creating and compiling vertex shader

    vshader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vshader, 1, &vertex_shader_code, NULL);
    glCompileShader(vshader);

    // Checking for errors

    glGetShaderiv(vshader, GL_COMPILE_STATUS, &sucess);

    if (!sucess)
    {
        glGetShaderInfoLog(vshader, 512, NULL, infolog);
        std::cerr << "[Error]: Shader Compilation Failed\n";
        std::cerr << infolog << "\n";
    }

    // creating and compiling fragment shader

    fshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fshader, 1, &fragment_shader_code, NULL);
    glCompileShader(fshader);

    // Checking for error

    glGetShaderiv(fshader, GL_COMPILE_STATUS, &sucess);

    if (!sucess)
    {
        glGetShaderInfoLog(fshader, 512, NULL, infolog);
        std::cerr << "[Error]: Shader Compilation Failed\n";
        std::cerr << infolog << "\n";
    }

    // Linking shader

    ID = glCreateProgram();
    glAttachShader(ID, vshader);
    glAttachShader(ID, fshader);
    glLinkProgram(ID);

    // Checkinh for linking errors

    glGetProgramiv(ID, GL_LINK_STATUS, &sucess);

    if (!sucess)
    {
        glGetProgramInfoLog(ID, 512, NULL, infolog);
        std::cerr << "[Error]: Shader Linking Failed\n";
        std::cerr << infolog << "\n";
    }

    // Deleting left shaders

    glDeleteShader(vshader);
    glDeleteShader(fshader);
}

int Shader::getID()
{

    return ID;
}