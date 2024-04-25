#include <raylib.h>
#include <raymath.h>
#include "player.h"

void MovePlayer(Player *player)
{
    switch (player->dir)
    {
    case D_UP:
        player->movement = (Vector2){0, -player->segments[0].size};
        break;
    case D_DOWN:
        player->movement = (Vector2){0, player->segments[0].size};
        break;
    case D_LEFT:
        player->movement = (Vector2){-player->segments[0].size, 0};
        break;
    case D_RIGHT:
        player->movement = (Vector2){player->segments[0].size, 0};
        break;
    default:
        break;
    }

    if (player->length == 1)
    {
        player->segments[0].pos.x += player->movement.x;
        player->segments[0].pos.y += player->movement.y;
    }
}

void UpdatePlayer(Player *player)
{
    MovePlayer(player);
}

void PlayerRender(Player *player)
{
    // render the player
    for (int i = 0; i <= player->length - 1; i++)
        DrawRectangle(player->segments[i].pos.x, player->segments[i].pos.y,
                      player->segments[i].size, player->segments[i].size,
                      player->segments[i].color);
}
