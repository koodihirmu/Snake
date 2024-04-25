#include <raylib.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

// Snake game main function

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game\n");
    SetTargetFPS(60);
    const Color backgroundcolor = {100, 130, 100};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(backgroundcolor);
        EndDrawing();
    }

    return 0;
}