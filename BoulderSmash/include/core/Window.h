#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "utils/MathHelper.h"

/// @brief Data for the mouse
typedef struct MouseCallbackData
{
	float data1;
	float data2;
};

/// @brief Data for the mouse
typedef struct MouseCallbackData MouseCallbackData;


/// @brief Window struct
typedef struct Window
{
    GLFWwindow* window;
    Vector3f* color;
};

/// @brief Window struct
typedef struct Window Window;

MouseCallbackData* mouseData;

/// @brief Sets the mouse' callback data
/// @param data1 
/// @param data2 
/// @return void
void SetMouseCallback(float data1, float data2)
{
    mouseData->data1 = data1;
    mouseData->data2 = data2;
}

/// @brief Gets the mouse' current data
/// @param void
/// @return MouseCallbackData*
MouseCallbackData* Window_GetMouseCallback()
{
    return mouseData;
}

/// @brief Gets the monitors width and height
/// @param void
/// @return Vector2i*
Vector2i* Window_GetDesktopResolution()
{
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    return MathHelper_CreateVector2i( mode->width, mode->height );
}

/// @brief Framebuffer size callback for GLFW
/// @param window 
/// @param width 
/// @param height 
/// @return void
void FSC(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

/// @brief Mouse callback for GLFW
/// @param window 
/// @param xposIn 
/// @param yposIn 
/// @return void
void MouseCallback(GLFWwindow* window, double xposIn, double yposIn)
{
	SetMouseCallback((float)xposIn, (float)yposIn);
}

/// @brief Generates the base values for a window to be rendered
/// @param window 
/// @param title 
/// @param width 
/// @param height 
/// @return void
void Window_GenerateWindow(Window* window, const char* title, int width, int height)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    mouseData = (MouseCallbackData*)malloc(sizeof(mouseData));

    if(width == 0 || height == 0)
    {
        window->window = glfwCreateWindow(*Window_GetDesktopResolution()[0], *Window_GetDesktopResolution()[1], title, NULL, NULL);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    }
    else
    {
        window->window = glfwCreateWindow(width, height, title, NULL, NULL);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
    }
        
    glfwMakeContextCurrent(window->window);
    glfwSetFramebufferSizeCallback(window->window, FSC);
    glfwSetCursorPosCallback(window->window, MouseCallback);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}

/// @brief Checks is the current window should close
/// @param window 
/// @return bool
bool Window_ShouldClose(Window* window)
{
    return glfwWindowShouldClose(window->window);
}

/// @brief Sets the background color of the current window
/// @param window 
/// @param color 
/// @return void
void Window_SetBackgroundColor(Window* window, Vector3f* color)
{
    window->color = color;
}

/// @brief Updates the windows color
/// @param window 
/// @return void
void Window_UpdateColor(Window* window)
{
    glClearColor((GLfloat)*window->color[0], (GLfloat)*window->color[1], (GLfloat)*window->color[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/// @brief Updates the window buffers
/// @param window 
/// @return void
void Window_UpdateBuffers(Window* window)
{
    glfwSwapBuffers(window->window);
    glfwPollEvents();
}

/// @brief Gets the current size of the current window
/// @param window 
/// @return Vector2i*
Vector2i* Window_GetWindowSize(Window* window)
{
    int width;
    int height;
    glfwGetWindowSize(window->window, &width, &height);
    return MathHelper_CreateVector2i(width, height);
}

/// @brief Gets the internal GLFWwindow reference
/// @param window 
/// @return GLFWwindow*
GLFWwindow* Window_GetInternal(Window* window)
{
    return window->window;
}

/// @brief Terminates the current window and frees allocated memory
/// @param window 
/// @return void
void Window_Terminate(Window* window)
{
    free(window->color);
    free(mouseData);
    glfwTerminate();
}

#endif