#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "rendering/Camera.h"
#include "rendering/Shader.h"
#include "rendering/Texture.h"
#include "core/Logger.h"
#include "utils/MathHelper.h"
#include "utils/FloatHelper.h"

const char* vertexShader = 
{
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos, 1.0f);\n"
    "TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    "}\n"
};

const char* fragmentShader = 
{
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec2 TexCoord;\n"
    "uniform sampler2D texture1;\n"
    "void main()\n"
    "{\n"
    "FragColor = texture(texture1, TexCoord);\n"
    "}\n"
};

/// @brief Renderer struct
typedef struct Renderer
{
    unsigned int VAO, VBO, EBO;
    float* vertices;
    Shader* shader;
    Texture* texture;
    Vector3f* position;
};

/// @brief Renderer struct
typedef struct Renderer Renderer;

/// @brief Initalizes the internal variables
/// @param renderer 
/// @param texturePath 
/// @return void
void Renderer_InternalInit(Renderer* renderer, const char* texturePath)
{
    renderer->shader = (Shader*)malloc(sizeof(renderer->shader));
    Shader_LoadFromConstChar(renderer->shader, vertexShader, fragmentShader);

    renderer->texture = (Texture*)malloc(sizeof(renderer->texture));
    Texture_LoadFromFile(renderer->texture, texturePath);
}

/// @brief Generates the base data for rendering an object using raw input data
/// @param renderer 
/// @param vertices 
/// @param verticesSize 
/// @return void
void Renderer_GenerateRawObject(Renderer* renderer, float vertices[], float verticesSize)
{
    glGenVertexArrays(1, &renderer->VAO);
    glGenBuffers(1, &renderer->VBO);

    glBindVertexArray(renderer->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, renderer->VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Shader_Use(renderer->shader);
    Shader_SetInt(renderer->shader, "texture1", 0);
}

/// @brief Generates a test object for rendering
/// @param renderer 
/// @param position 
/// @return void
void Renderer_GenerareObject(Renderer* renderer, Vector3f* position, const char* texturePath)
{
    Renderer_InternalInit(renderer, texturePath);
    renderer->position = position;

    float vertices[] =
    {
        -0.5f + DEPRE(position[0]), -0.5f + DEPRE(position[1]), -0.5f + DEPRE(position[2]),  0.0f, 0.0f,
         0.5f + DEPRE(position[0]), -0.5f + DEPRE(position[1]), -0.5f + DEPRE(position[2]),  1.0f, 0.0f,
         0.5f + DEPRE(position[0]),  0.5f + DEPRE(position[1]), -0.5f + DEPRE(position[2]),  1.0f, 1.0f,
         0.5f + DEPRE(position[0]),  0.5f + DEPRE(position[1]), -0.5f + DEPRE(position[2]),  1.0f, 1.0f,
        -0.5f + DEPRE(position[0]),  0.5f + DEPRE(position[1]), -0.5f + DEPRE(position[2]),  0.0f, 1.0f,
        -0.5f + DEPRE(position[0]), -0.5f + DEPRE(position[1]), -0.5f + DEPRE(position[2]),  0.0f, 0.0f,
    };
    renderer->vertices = vertices;

    Renderer_GenerateRawObject(renderer, vertices, sizeof(vertices));
}

/// @brief Draws tthe current object from generated data
/// @param renderer 
/// @return void
void Renderer_Draw(Renderer* renderer, Camera* camera)
{
    //Logger_WriteConsole("MMMMM", "Renderer", LOGLEVEL_INFO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, renderer->texture->textureID);

    Shader_Use(renderer->shader);

    Logger_WriteConsole("Renn", "Renderer", LOGLEVEL_INFO);

    //Matrix4f* transform = MathHelper_Matrix4fIdentity();
    //glm_translate(*CPMToDPM(transform), *renderer->position);
    
    //Shader_SetMat4(renderer->shader, "model", transform);
    //Shader_SetMat4(renderer->shader, "view", Camera_GetProjection(camera)->view);
    //Shader_SetMat4(renderer->shader, "projection", Camera_GetProjection(camera)->projection);
    Logger_WriteConsole("Renn++", "Renderer", LOGLEVEL_INFO);
    
    Logger_WriteConsole("Renn dun", "Renderer", LOGLEVEL_INFO);

    glBindVertexArray(renderer->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 18);
}

/// @brief Frees allocated data
/// @param renderer 
/// @return void
void Renderer_Cleanup(Renderer* renderer)
{
    free(renderer->vertices);
}   

#endif