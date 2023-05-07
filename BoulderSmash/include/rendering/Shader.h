#ifndef SHADER_H
#define SHADER_H

#define bool _Bool

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fileapi.h>
#include "utils/MathHelper.h"

/// @brief Shader struct
typedef struct Shader
{
    unsigned int programID;
};

/// @brief Shader struct
typedef struct Shader Shader;

/// @brief Loads a shader from a const char* into memory to be processed
/// @param shader 
/// @param vertexShaderPath 
/// @param fragmentShaderPath 
/// @return void
/// @deprecated Replaced by Shader_LoadFromFile
void Shader_LoadFromConstChar(Shader* shader, const char* vertexShaderPath, const char* fragmentShaderPath)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderPath, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s", infoLog);
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderPath, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n %s", infoLog);
    }

    shader->programID = glCreateProgram();
    glAttachShader(shader->programID, vertexShader);
    glAttachShader(shader->programID, fragmentShader);
    glLinkProgram(shader->programID);

    glGetProgramiv(shader->programID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader->programID, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n %s", infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

/// @brief Loads a shader from a file into memory to be processed
/// @param shader 
/// @param vertexShaderPath 
/// @param fragmentShaderPath 
/// @return void
void Shader_LoadFromFile(Shader* shader, const char* vertexPath, const char* fragmentPath)
{
    /*FILE* vertexFile = fopen(vertexPath, "rb");
    unsigned char* vertexResult;
    while(fseek(vertexFile, 0, 0))
    {

    }
    fclose(vertexFile);*/
    
}

/// @brief Retrives the generated programID of the current shader
/// @param shader 
/// @return unsigned int
unsigned int Shader_GetID(Shader* shader)
{
    return shader->programID;
}

/// @brief Activates the shader to set values
/// @param shader 
/// @return void
void Shader_Use(Shader* shader)
{
    glUseProgram(shader->programID);
}

/// @brief Sets a Matrix4f value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetMat4(Shader* shader, const char* name, Matrix4f* mat)
{
    glUniformMatrix4fv(glGetUniformLocation(shader->programID, name), 1, GL_FALSE, (const GLfloat*)**&mat);
}

/// @brief Sets a boolean value within the current shader
/// @param shader 
/// @param name 
/// @param value
/// @return void 
void Shader_SetBool(Shader* shader, const char* name, bool value)
{
    glUniform1i(glGetUniformLocation(shader->programID, name), (int)value);
}

/// @brief Sets an integer value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetInt(Shader* shader, const char* name, int value)
{
    glUniform1i(glGetUniformLocation(shader->programID, name), value);
}

/// @brief Sets a float value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetFloat(Shader* shader, const char* name, float value)
{
    glUniform1f(glGetUniformLocation(shader->programID, name), value);
}

/// @brief Sets a Vector2f value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetVec2(Shader* shader, const char* name, Vector2f* value)
{
    glUniform2fv(glGetUniformLocation(shader->programID, name), 1, (GLfloat*)*&value[0]);
}

/// @brief Sets a Vector3f value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetVec3(Shader* shader, const char* name, Vector3f* value)
{
    glUniform3fv(glGetUniformLocation(shader->programID, name), 1, (GLfloat*)*&value[0]);
}

/// @brief Sets a Vector4f value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetVec4(Shader* shader, const char* name, Vector4f* value)
{
    glUniform4fv(glGetUniformLocation(shader->programID, name), 1, (GLfloat*)*&value[0]);
}

/// @brief Sets a Matrix2f value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetMat2(Shader* shader, const char* name, Matrix2f* mat)
{
    glUniformMatrix2fv(glGetUniformLocation(shader->programID, name), 1, GL_FALSE, (const GLfloat*)**&mat);
}

/// @brief Sets a Matrix3f value within the current shader
/// @param shader 
/// @param name 
/// @param value 
/// @return void
void Shader_SetMat3(Shader* shader, const char* name, Matrix3f* mat)
{
    glUniformMatrix3fv(glGetUniformLocation(shader->programID, name), 1, GL_FALSE, (const GLfloat*)**&mat);
}

#endif