#include <raylib.h>
#include <stdio.h>
#include "player.h"
#include "apple.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400
#define GRID_SIZE 10

static double time = 0;

// Snake game main function
// TODO:
// Rectangle player that moves certain amount in certain time
// if player hits border they are transformed to the other side
// with the same momentum
// apples that the snake eats
// when snake eats an apple they grow 1 unit
// if snake hits itself game over

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game\n");
    SetTargetFPS(60);
    const Color backgroundcolor = {100, 130, 100};

    // initialize the player
    Player player;
    player.length = 1;
    Segment firstsegment = {(Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}, GRID_SIZE, BLACK};
    player.segments[0] = firstsegment;
    player.movement = (Vector2){player.segments[0].size, 0};
    bool blink = true;

    Apple apple;
    apple.col = RED;
    apple.size = GRID_SIZE;
    // WINDOW_WIDTH / grid size
    apple.pos = (Vector2){GetRandomValue(1, (WINDOW_WIDTH / GRID_SIZE) - 1) * GRID_SIZE,
                          GetRandomValue(1, (WINDOW_HEIGHT / GRID_SIZE) - 1) * GRID_SIZE};

    while (!WindowShouldClose())
    {
        switch (GetKeyPressed())
        {
        case KEY_W:
            if (player.dir != D_DOWN || player.length == 1)
                player.dir = D_UP;
            break;
        case KEY_S:
            if (player.dir != D_UP || player.length == 1)
                player.dir = D_DOWN;
            break;
        case KEY_A:
            if (player.dir != D_RIGHT || player.length == 1)
                player.dir = D_LEFT;
            break;
        case KEY_D:
            if (player.dir != D_LEFT || player.length == 1)
                player.dir = D_RIGHT;
            break;
        default:
            break;
        }

        if ((int)(time * 10) % 10 % 2 == 0 && blink)
        {
            // RespawnApple(&apple, GRID_SIZE);
            if (CheckCollisionPointCircle(player.segments[0].pos, apple.pos, 5))
            {
                RespawnApple(&apple, GRID_SIZE);
                AddSegment(&player);
            }
            UpdatePlayer(&player);
            blink = false;
        }
        else if ((int)(time * 10) % 10 % 2 != 0 && !blink)
        {
            blink = true;
        }

        BeginDrawing();
        ClearBackground(backgroundcolor);
        RenderApple(&apple);
        PlayerRender(&player);
        EndDrawing();
        time += GetFrameTime();
    }

    return 0;
}