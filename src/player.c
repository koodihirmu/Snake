#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include "player.h"
#include "apple.h"

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

    for (int i = player->length - 1; i > 0; i--)
    {
        player->segments[i].pos = player->segments[i - 1].pos;
    }
    player->segments[0].pos = Vector2Add(player->segments[0].pos, player->movement);
}

bool CheckSelfCollision(Player *player)
{
    //
    for (int i = 1; i < player->length - 1; i++)
    {

        if (Vector2Equals(player->segments[0].pos, player->segments[i].pos) != 0)
        {
            return true;
        }
    }
    return false;
}

void AddSegment(Player *player)
{
    //
    Segment firstsegment = {player->segments[player->length - 2].pos,
                            player->segments[0].size, BLACK};
    player->segments[player->length] = firstsegment;
    player->length += 1;
    printf("Segment Added!\n");
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
