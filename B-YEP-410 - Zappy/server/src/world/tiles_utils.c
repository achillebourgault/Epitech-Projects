/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include "../../include/server.h"

void add_ressource_to_tile(item_t *item, tile_t *tile)
{
    int alloc = 0;
    item_t **new_ressources;

    for (; tile->items[alloc] != NULL; alloc++);
    new_ressources = safe_malloc(sizeof(item_t *) * (alloc + 2));
    for (alloc = 0; tile->items[alloc] != NULL; alloc++)
        new_ressources[alloc] = tile->items[alloc];
    new_ressources[alloc] = item;
    new_ressources[alloc + 1] = NULL;
    tile->items = new_ressources;
}

tile_t *init_tile(const int pos[2])
{
    tile_t *res = safe_malloc(sizeof(tile_t));

    res->pos[X] = pos[X];
    res->pos[Y] = pos[Y];
    res->items = safe_malloc(sizeof(item_t *) * 1);
    res->items[0] = NULL;
    res->players = safe_malloc(sizeof(player_t *) * 1);
    res->players[0] = NULL;
    return res;
}

tile_t *get_tile_by_pos(const int pos[2], world_t *world)
{
    for (int y = 0; world->map[y] != NULL; y++) {
        for (int x = 0; world->map[y][x] != NULL; x++) {
            if (world->map[y][x]->pos[X] == pos[X] &&
                world->map[y][x]->pos[Y] == pos[Y])
                return world->map[y][x];
        }
    }
    return NULL;
}