cmake_minimum_required(VERSION 3.16)

project(TicTacToe_OpenGL
    VERSION 1.0
    LANGUAGES C CXX
)

# ===============================
# C++ Standard
# ===============================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ===============================
# Collect Source Files
# ===============================
file(GLOB_RECURSE PROJECT_SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

# ===============================
# Create Executable
# ===============================
add_executable(TicTacToe_OpenGL
    ${PROJECT_SOURCES}
)

# ===============================
# Include Directories
# ===============================
target_include_directories(TicTacToe_OpenGL
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# ===============================
# Dependencies (GLFW + GLEW)
# ===============================
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)

target_link_libraries(TicTacToe_OpenGL
    PRIVATE
        glfw
        GLEW::GLEW
        opengl32
)

# ===============================
# Windows: Copy GLEW DLL next to exe
# ===============================
if (WIN32)
    add_custom_command(TARGET TicTacToe_OpenGL POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:GLEW::GLEW>"
            "$<TARGET_FILE_DIR:TicTacToe_OpenGL>"
    )
endif()
