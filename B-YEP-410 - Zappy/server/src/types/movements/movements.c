/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include "../../../include/server.h"

int move_north(server_t *server, player_t *player)
{
    if (player->pos[Y] == 0)
        player->pos[Y] = (server->world->dimensions[Y] - 1);
    else
        player->pos[Y] -= 1;
    return 0;
}

int move_south(server_t *server, player_t *player)
{
    if (player->pos[Y] == server->world->dimensions[Y]  - 1)
        player->pos[Y] = 0;
    else
        player->pos[Y] += 1;
    return 0;
}

int move_east(server_t *server, player_t *player)
{
    if (player->pos[X] == server->world->dimensions[X] - 1)
        player->pos[X] = 0;
    else
        player->pos[X] += 1;
    return 0;
}

int move_west(server_t *server, player_t *player)
{
    if (player->pos[X] == 0) {
        player->pos[X] = server->world->dimensions[X] - 1;
    } else
        player->pos[X] -= 1;
    return 0;
}

void move(server_t *server, player_t *player, int direction)
{
    int (*move[4])(server_t *, player_t *) = {move_north,
    move_east, move_south, move_west};
    tile_t *old = get_tile_by_pos(player->pos, server->world);
    char *dir[4] = {"NORTH", "EAST", "SOUTH", "WEST"};

    if (old == NULL)
        printf("OLD TILE IS NULL\n");
    printf("Prepare to move to %s\n", dir[direction - 1]);

    move[direction - 1](server, player);
    remove_player_to_tile(player, old);
    add_player_to_tile(player, get_tile_by_pos(player->pos, server->world));
}