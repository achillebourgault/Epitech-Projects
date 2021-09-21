/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/types/elevation.h"

elevation_t *init_elevation(player_t *player)
{
    elevation_t *elv = safe_malloc(sizeof(elevation_t));
    int elevations[7][6] = {{1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0},
        {2, 0, 1, 0, 2, 0}, {1, 1, 2, 0, 1, 0}, {1, 2, 1, 3, 0, 0},
        {1, 2, 3, 0, 1, 0}, {2, 2, 2, 2, 2, 1}};

    elv->stones_required[ITEM_LINEMATE] = elevations[player->level -
        1][ITEM_LINEMATE];
    elv->stones_required[ITEM_DERAUMERE] = elevations[player->level -
        1][ITEM_DERAUMERE];
    elv->stones_required[ITEM_SIBUR] = elevations[player->level -
        1][ITEM_SIBUR];
    elv->stones_required[ITEM_MENDIANE] = elevations[player->level -
        1][ITEM_MENDIANE];
    elv->stones_required[ITEM_PHIRAS] = elevations[player->level -
        1][ITEM_PHIRAS];
    elv->stones_required[ITEM_THYSTAME] = elevations[player->level -
        1][ITEM_THYSTAME];
    return elv;
}

int get_players_required(player_t *player)
{
    int players_required[7] = {1, 2, 2, 4, 4, 6, 6};
    int res;

    if (player->level >= 7)
        res = players_required[6];
    else
        res = players_required[player->level + 1];
    return res;
}

int ask_elevation(server_t *server, player_t *player)
{
    elevation_t *elv;

    if (get_total_players(server) < get_players_required(player))
        return error(
            "Info: Cannot open Ritual Elevation, not enough players.\n");
    elv = init_elevation(player);
    elv->player = player;
    elv->new_level = player->level + 1;
    for (int i = 0; i < 6; i++)
        if (player_contains_at_least(player, i, elv->stones_required[i]) ==
            FALSE)
            return error("Info: Cannot open Ritual Elevation, "
            "Player don't have required stones.\n");
    for (int i = 0; i < 6; i++)
        use_item(player, i, elv->stones_required[i]);
    printf("Elevation done !\n");
    free(elv);
    return TRUE;
}