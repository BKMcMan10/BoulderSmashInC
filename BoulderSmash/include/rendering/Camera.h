#ifndef CAMERA_H
#define CAMERA_H

#include "core/Input.h"
#include "core/Window.h"
#include "utils/MathHelper.h"

typedef struct CameraProjection
{
    Matrix4f* view;
    Matrix4f* projection;
};

typedef struct CameraProjection CameraProjection;

/// @brief Struct Camera
typedef struct Camera
{
    Window* window;

    bool isPaused;

    Matrix4f* view;
	Matrix4f* projection;

	Vector3f* position;
	Vector3f* front;
	Vector3f* up;

	float yaw;
	float pitch;
	float lastX;
	float lastY;
	float fov;

	float deltaTime;
	float lastFrame;
};

/// @brief Struct Camera
typedef struct Camera Camera;

void Camera_Init(Camera* camera, Window* window)
{
    camera->isPaused = false;
    camera->view = MathHelper_Matrix4fIdentity();
    camera->projection = MathHelper_Matrix4fIdentity();
    camera->position = MathHelper_CreateVector3f(0.0f, 0.0f, 0.0f);
    camera->front = MathHelper_CreateVector3f(0.0f, 0.0f, -1.0f);
    camera->up = MathHelper_CreateVector3f(0.0f, 1.0f, 0.0f);
    camera->yaw = -90.0f;
    camera->pitch = 0.0f;
    camera->lastX = 800.0f / 2.0;
    camera->lastY = 600.0 / 2.0;
    camera->fov = 45.0f;
    camera->deltaTime = 0.0f;
    camera->lastFrame = 0.0f;
    camera->window = window;

    glm_perspective(radians(75.0f), (float)*Window_GetWindowSize(window)[0] / (float)*Window_GetWindowSize(window)[1], 0.01f, 70.0f, *(mat4*)*camera->projection); //
    glm_look(*camera->position, *MathHelper_CombineVector3f(camera->position, camera->front), *camera->up, *(mat4*)*camera->view);
    Input_SetCursorMode(false);
}

void Camera_SetPosition(Camera* camera, Vector3f* position)
{
    glm_translate(*CPMToDPM(camera->view), *position);
}

void Camera_UpdateInput(Camera* camera)
{
    Logger_WriteConsole("CAMMMupdate", "Camera", LOGLEVEL_INFO);
    if (!camera->isPaused)
    {
        float cameraSpeed = (float)(2.5 * camera->deltaTime);
        if (Input_GetKeyDown(GLFW_KEY_W))
        {
            MathHelper_CombineVector3f(camera->position, MathHelper_MultiplyVector3f(cameraSpeed, camera->front));

            if (Input_GetKeyDown(GLFW_KEY_LEFT_CONTROL))
            {

                MathHelper_CombineVector3f(camera->position, MathHelper_MultiplyVector3f(cameraSpeed * 3, camera->front));
            }
        }
        
        if (Input_GetKeyDown(GLFW_KEY_S))
            MathHelper_SubtractVector3f(camera->position, MathHelper_MultiplyVector3f(cameraSpeed, camera->front));
        if (Input_GetKeyDown(GLFW_KEY_A))
            MathHelper_SubtractVector3f(camera->position, MathHelper_MultiplyVector3f(cameraSpeed, MathHelper_Normalize(MathHelper_Cross(camera->front, camera->up))));
        if (Input_GetKeyDown(GLFW_KEY_D))
            MathHelper_CombineVector3f(camera->position, MathHelper_MultiplyVector3f(cameraSpeed, MathHelper_Normalize(MathHelper_Cross(camera->front, camera->up))));
    }
    

    if (Input_GetKeyDown(GLFW_KEY_ESCAPE) && !camera->isPaused)
    {
        Input_SetCursorMode(true);

        camera->isPaused = true;
    }
    else if (Input_GetKeyDown(GLFW_KEY_ESCAPE) && camera->isPaused)
    {
        Input_SetCursorMode(false);

        camera->isPaused = false;
    }

    if (camera->isPaused) return;
    Logger_WriteConsole("CAMMMupdate++", "Camera", LOGLEVEL_INFO);
    MouseCallbackData* mouseData = Window_GetMouseCallback();
    float xpos = mouseData->data1;
    float ypos = mouseData->data2;

    float xoffset = xpos - camera->lastX;
    float yoffset = camera->lastY - ypos;
    camera->lastX = xpos;
    camera->lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    camera->yaw += xoffset;
    camera->pitch += yoffset;

    if (camera->pitch > 89.0f)
        camera->pitch = 89.0f;
    if (camera->pitch < -89.0f)
        camera->pitch = -89.0f;

    Vector3f* front1 = (Vector3f*)malloc(sizeof(front1));
    *front1[0] = cos(radians(camera->yaw)) * cos(radians(camera->pitch));
    *front1[1] = sin(radians(camera->pitch));
    *front1[2] = sin(radians(camera->yaw)) * cos(radians(camera->pitch));
    camera->front = MathHelper_Normalize(front1);

    Logger_WriteConsole("CAMMMupdate dun", "Camera", LOGLEVEL_INFO);
}

void Camera_Update(Camera* camera)
{
    Logger_WriteConsole("CAMMM", "Camera", LOGLEVEL_INFO);
    float currentFrame = (float)(glfwGetTime());
    camera->deltaTime = currentFrame - camera->lastFrame;
    camera->lastFrame = currentFrame;

    glm_look(*camera->position, *MathHelper_CombineVector3f(camera->position, camera->front), *camera->up, *(mat4*)*camera->view);
    Logger_WriteConsole("CAMMM++", "Camera", LOGLEVEL_INFO);

    Camera_UpdateInput(camera);
}

Vector3f* Camera_GetPosition(Camera* camera)
{
    return camera->position;
}

CameraProjection* Camera_GetProjection(Camera* camera)
{
    CameraProjection* out = (CameraProjection*)malloc(sizeof(out));
    out->view = camera->view;
    out->projection = camera->projection;
    return out;
}

#endif