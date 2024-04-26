#include <raylib.h>
#include <stdio.h>
#include "player.h"
#include "apple.h"
#include "config.h"

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
    bool blink = true;
    bool GameOver = false;

    // initialize the player
    Player player;
    player.length = 1;
    Segment firstsegment = {(Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2}, GRID_SIZE, BLACK};
    player.segments[0] = firstsegment;
    player.movement = (Vector2){player.segments[0].size, 0};

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
            if (player.lastdir != D_DOWN)
                player.dir = D_UP;
            break;
        case KEY_S:
            if (player.lastdir != D_UP)
                player.dir = D_DOWN;
            break;
        case KEY_A:
            if (player.lastdir != D_RIGHT)
                player.dir = D_LEFT;
            break;
        case KEY_D:
            if (player.lastdir != D_LEFT)
                player.dir = D_RIGHT;
            break;
        default:
            break;
        }

        if ((int)(time * 10) % 10 % 2 == 0 && blink && !GameOver)
        {
            if (player.length < 10)
            {
                AddSegment(&player);
            }
            if (CheckCollisionPointCircle(player.segments[0].pos, apple.pos, 5))
            {
                RespawnApple(&apple);
                AddSegment(&player);
            }
            UpdatePlayer(&player); // motion vector updated here
            // TODO: Need to figure out to check the future location of the head
            // Now this uses the old head movement so it detects the collision too early
            if (CheckSelfCollision(&player))
            {
                GameOver = true;
            }
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
        if (GameOver)
        {
            DrawText("GAME OVER!\n", WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 10, 20, BLACK);
        }
        EndDrawing();
        time += GetFrameTime();
    }

    return 0;
}