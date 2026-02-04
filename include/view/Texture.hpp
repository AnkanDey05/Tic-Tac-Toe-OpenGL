#pragma once
#include <GL/glew.h>
#include <string>
#include <iostream>
#include "../../external/stb_image.h"

class Texture
{
private:
    unsigned int ID = 0;
    int width = 0, height = 0, channels = 0;

public:
    Texture() = default;

    ~Texture()
    {
        if (ID)
            glDeleteTextures(1, &ID);
    }

    bool loadFromFile(const std::string& path)
    {
        stbi_set_flip_vertically_on_load(true);

        unsigned char* data = stbi_load(
            path.c_str(),
            &width,
            &height,
            &channels,
            0
        );

        if (!data)
        {
            std::cerr << "Failed to load texture: " << path << "\n";
            return false;
        }

        GLenum format;
        if (channels == 1) format = GL_RED;
        else if (channels == 3) format = GL_RGB;
        else if (channels == 4) format = GL_RGBA;
        else
        {
            std::cerr << "Unsupported channel count\n";
            stbi_image_free(data);
            return false;
        }

        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            format,
            width,
            height,
            0,
            format,
            GL_UNSIGNED_BYTE,
            data
        );

        glGenerateMipmap(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);

        stbi_image_free(data);
        return true;
    }

    void bind(unsigned int slot = 0) const
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, ID);
    }

    void unbind() const
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};
