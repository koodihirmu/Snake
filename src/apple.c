#include <raylib.h>
#include "apple.h"

void RenderApple(Apple *apple)
{
    DrawRectangle(apple->pos.x, apple->pos.y, apple->size,
                  apple->size, apple->col);
}

void RespawnApple(Apple *apple, int GRID_SIZE)
{
    apple->pos = (Vector2){GetRandomValue(1, (GetScreenWidth() / GRID_SIZE) - 1) * GRID_SIZE,
                           GetRandomValue(1, (GetScreenHeight() / GRID_SIZE) - 1) * GRID_SIZE};
}