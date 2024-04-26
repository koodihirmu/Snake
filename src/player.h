#include <raylib.h>
#pragma once

#define MAX_SEGMENT 100

typedef enum
{
    D_UP,
    D_DOWN,
    D_LEFT,
    D_RIGHT,
    D_COUNT,
} Direction;

typedef struct
{
    // segment size and position
    Vector2 pos;
    float size;
    Color color;
} Segment;

typedef struct
{
    // list of segments to render
    Segment segments[MAX_SEGMENT];
    // amount of segments currently
    int length;
    Direction dir;
    Vector2 movement;
} Player;

bool CheckSelfCollision(Player *player);
void AddSegment(Player *player);
void UpdatePlayer(Player *player); // update player position
void PlayerRender(Player *player); // render player
