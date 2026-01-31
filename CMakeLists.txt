cmake_minimum_required(VERSION 3.16)

project(TicTacToe_OpenGL LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW + GLEW (NO GLAD ANYWHERE)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

add_executable(TicTacToe_OpenGL
    src/main.cpp
)

target_link_libraries(TicTacToe_OpenGL
    PRIVATE
        glfw
        GLEW::GLEW
        opengl32
)
if (WIN32)
    add_custom_command(TARGET TicTacToe_OpenGL POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:GLEW::GLEW>"
            "$<TARGET_FILE_DIR:TicTacToe_OpenGL>"
    )
endif()
