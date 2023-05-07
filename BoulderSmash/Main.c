#include "core/Window.h"
#include "core/Input.h"
#include "core/Logger.h"
#include "rendering/Camera.h"
#include "rendering/Renderer.h"
#include "utils/FileHelper.h"
#include "utils/StringHelper.h"

int main(void)
{
    Logger_WriteConsole("Hello, GLFW 3.3.8!", "Main", LOGLEVEL_INFO);
    //Logger_WriteConsole(FileHelper_LoadFileFromPath("build.txt"), "Main", LOGLEVEL_INFO);

    Window* window = (Window*)malloc(sizeof(window));
    Renderer* renderer = (Renderer*)malloc(sizeof(renderer));
    Camera* camera = (Camera*)malloc(sizeof(camera));

    Window_GenerateWindow(window, "BoulderSmash* 1.0.8a", 800, 450);
    Window_SetBackgroundColor(window, MathHelper_CreateVector3f(0, 0, 0.25f));

    Input_InitWindow(Window_GetInternal(window));

    Renderer_GenerareObject(renderer, MathHelper_CreateVector3f(0, 0, 0), "assets/images/stone.png");

    //Camera_Init(camera, window);
    
    while(!Window_ShouldClose(window))
    {
        MemoryHelper_Update();

        Window_UpdateColor(window);

        //Camera_Update(camera);

        Renderer_Draw(renderer, camera);

        Window_UpdateBuffers(window);
    }

    Renderer_Cleanup(renderer);
    Window_Terminate(window);
    free(renderer);
    free(window);

    return 0;
}