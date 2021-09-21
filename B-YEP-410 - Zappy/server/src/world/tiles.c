/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/world.h"
#include "../../include/server.h"


void add_player_to_tile(player_t *player, tile_t *tile)
{
    int alloc = 0;
    player_t **new_ressources;

    for (; tile->players[alloc] != NULL; alloc++);
    new_ressources = safe_malloc(sizeof(player_t *) * (alloc + 2));
    new_ressources[0] = player;
    if (tile->players[0] != NULL) {
        for (alloc = 1; tile->players[alloc] != NULL; alloc++)
            new_ressources[alloc] = tile->players[alloc];
    }
    new_ressources[alloc + 1] = NULL;
    tile->players = new_ressources;
}

int count_contents(tile_t *tile)
{
    int res = 0;

    for (int i = 0; tile->players[i] != NULL; i++)
        res += 7;
    for (int i = 0; tile->items[i] != NULL; i++)
        res += strlen(get_item_name_by_type(tile->items[i]->type)) + 1;
    return res;
}

char *get_content_on_tile(tile_t *tile)
{
    char *res;

    if (tile == NULL)
        perror("Error: Tile is null [get_content_on_tile]\n");
    res = safe_malloc(sizeof(char) * (count_contents(tile) + 1));
    res[0] = '\0';
    for (int i = 0; tile->players[i] != NULL; i++) {
        if (i != 0)
            strcat(res, " ");
        strcat(res, "player");
    }
    for (int i = 0; tile->items[i] != NULL; i++) {
        if (i == 0)
            strcat(res, " ");
        strcat(res, get_item_name_by_type(tile->items[i]->type));
        if (tile->items[i + 1] != NULL)
            strcat(res, " ");
    }
    return res;
}