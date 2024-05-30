#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int screenWidth = 800;
int screenHeight = 450;

void UpdateDrawFrame(void);     // Update and Draw one frame

void UpdateDrawFrame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Genesis");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    CloseWindow();        // Close window and OpenGL context

    return 0;
}
