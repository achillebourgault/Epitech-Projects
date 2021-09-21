/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/world.h"
#include "../../include/server.h"

int tile_contains_item(item_t *item, int nb, tile_t *tile)
{
    int res = FALSE;
    int nb_comp = 0;

    for (int i = 0; tile->items[i] != NULL; i++) {
        if (tile->items[i] == item)
            nb_comp++;
    }
    if (nb_comp == nb)
        res = TRUE;
    return res;
}

void remove_player_to_tile(player_t *item, tile_t *tile)
{
    int alloc = 0;
    player_t **new_ressources;

    for (; tile->players[alloc] != NULL; alloc++);
    new_ressources = safe_malloc(sizeof(player_t *) * (alloc + 1));
    for (int i = 0; tile->players[i] != NULL; i++) {
        if (tile->players[i] != item) {
            new_ressources[alloc] = tile->players[i];
            alloc++;
        }
    }
    new_ressources[alloc] = NULL;
    tile->players = new_ressources;
}

void remove_ressource_to_tile(item_t *item, tile_t *tile)
{
    int alloc = 0;
    item_t **new_ressources;
    int cpt = 0;

    for (; tile->items[alloc] != NULL; alloc++);
    new_ressources = safe_malloc(sizeof(item_t *) * (alloc + 1));
    for (alloc = 0; tile->items[alloc] != NULL; alloc++) {
        if (tile->items[alloc]->type == item->type)
            continue;
        new_ressources[cpt] = tile->items[alloc];
        cpt++;
    }
    new_ressources[cpt] = NULL;
    tile->items = new_ressources;
}