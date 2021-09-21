/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include "../../include/types/elevation.h"

int player_contains_at_least(player_t *player, int item, int nb)
{
    int res = FALSE;

    if (item == ITEM_FOOD) {
        if (player->inventory->food >= nb)
            res = TRUE;
    } else if (player->inventory->stones[item] >= nb)
        res = TRUE;
    return res;
}

int get_total_players(server_t *server)
{
    int res = 0;
    int team_size;

    for (int i = 0; server->teams[i] != NULL; i++) {
        for (team_size = 0; server->teams[i]->players[team_size]
        != NULL; team_size++);
        res += team_size;
    }
    return res;
}

player_t *get_player_by_index(player_t **players, int index)
{
    if (players == NULL)
        return NULL;
    for (int i = 0; players[i] != NULL; i++) {
        if (i == index)
            return players[i];
    }
    return NULL;
}

player_t **get_all_players(server_t *server)
{
    player_t **res;
    int alloc = 0;

    for (int i = 0, p = 0; server->teams[i] != NULL; i++) {
        for (p = 0; server->teams[i]->players[p] != NULL; p++);
        alloc += p;
    }
    res = safe_malloc(sizeof(player_t *) * (alloc + 1));
    for (int i = 0, p = 0, alloc = 0; server->teams[i] != NULL; i++) {
        for (p = 0; server->teams[i]->players[p] != NULL; p++, alloc++)
            res[alloc] = server->teams[i]->players[p];
    }
    res[alloc] = NULL;
    return res;
}