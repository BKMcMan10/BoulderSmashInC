#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include "core/Logger.h"
#include "utils/StringHelper.h"

/// @brief Texture struct
struct Texture
{
    unsigned int textureID;
    int width, height;
};

/// @brief Texture struct
typedef struct Texture Texture;

/// @brief Loads a texture into memory from the specified file path
/// @param texture
/// @param path 
/// @return void
void Texture_LoadFromFile(Texture* texture, const char* path)
{
    glGenTextures(1, &texture->textureID);

    int nrComponents;

    unsigned char* data = stbi_load(path, &texture->width, &texture->height, &nrComponents, 0);
    stbi_set_flip_vertically_on_load(1);

    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, texture->textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, texture->width, texture->height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        Logger_WriteConsole(StringHelper_CombineString(StringHelper_CombineString("Failed to load texture at: '", path), "'."), "Texture", LOGLEVEL_ERROR);
        stbi_image_free(data);
    }
}

#endif