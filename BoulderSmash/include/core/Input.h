#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* window;
bool hasBeenInitalized = false;

/// @brief Initalizes the global Input manager
/// @param win 
/// @return void
void Input_InitWindow(GLFWwindow* win)
{
    window = win;
    hasBeenInitalized = true;
}

/// @brief Checks if a certain key is pressed
/// @param key 
/// @return bool
bool Input_GetKeyDown(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS && hasBeenInitalized;
}

/// @brief Checks if a certain key is released
/// @param key 
/// @return 
bool Input_GetKeyUp(int key)
{
    return glfwGetKey(window, key) == GLFW_RELEASE && hasBeenInitalized;
}

/// @brief Checks if a certain mouse button is pressed
/// @param button 
/// @return bool
bool Input_GetMouseButtonDown(int button)
{
    return glfwGetMouseButton(window, button) == GLFW_PRESS && hasBeenInitalized;
}

/// @brief Checks if a certain mouse button is released
/// @param button 
/// @return bool
bool Input_GetMouseButtonUp(int button)
{
    return glfwGetMouseButton(window, button) == GLFW_RELEASE && hasBeenInitalized;
}

void Input_SetCursorMode(bool value)
{
    if(!value)
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    else
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

#endif