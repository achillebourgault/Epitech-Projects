/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/server.h"

player_t *get_player_by_socket(server_t *server, int socket)
{
    player_t *player = NULL;

    for (int j = 0; server->teams[j] != NULL; j++) {
        for (int i = 0; server->teams[j]->players[i] != NULL; i++) {
            if (server->teams[j]->players[i]->socket == socket) {
                player = server->teams[j]->players[i];
                return (player);
            }
        }
    }
    return player;
}

player_t *create_player(int socket, int dimensions[2], server_t *server)
{
    player_t *res = safe_malloc(sizeof(player_t));

    res->inventory = init_inventory();
    res->level = 1;
    res->pos[X] = (rand() % ((dimensions[X] - 1) - 0 + 1)) + 0;
    res->pos[Y] = (rand() % ((dimensions[Y] - 1) - 0 + 1)) + 0;
    res->action = 0;

    printf("Spawn player on tile Y: %d X: %d\n", res->pos[Y], res->pos[X]);
    res->time_units = CONFIG_DEFAULT_TIME_UNITS;
    res->socket = socket;
    res->vision = init_vision(NORTH, server, res);
    add_player_to_tile(res, get_tile_by_pos(res->pos, server->world));
    return res;
}

void free_player(player_t *player)
{
    free(player->inventory);
    free(player->vision);
}