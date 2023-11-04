#include "raylib.h"

int main()
{
    InitWindow(640, 480, "Pong[Raylib]");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Ponggame", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
    return 0;
}
