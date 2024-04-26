#include <raylib.h>
#pragma once

typedef struct
{
    Vector2 pos;
    float size;
    Color col;
} Apple;

void RenderApple(Apple *apple);
void RespawnApple(Apple *apple);
