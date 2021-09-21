/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/server.h"
#include "world.h"

int get_item_count_in_tile(tile_t *tile, int item_type)
{
    int count = 0;

    for (int i = 0; tile->items[i] != NULL; i++) {
        if (tile->items[i]->type == item_type)
            count++;
    }
    return count;
}

int *get_items_in_tile(tile_t *tile)
{
    int *res = malloc(sizeof(int) * 7);

    res[0] = get_item_count_in_tile(tile, ITEM_LINEMATE);
    res[1] = get_item_count_in_tile(tile, ITEM_DERAUMERE);
    res[2] = get_item_count_in_tile(tile, ITEM_SIBUR);
    res[3] = get_item_count_in_tile(tile, ITEM_MENDIANE);
    res[4] = get_item_count_in_tile(tile, ITEM_PHIRAS);
    res[5] = get_item_count_in_tile(tile, ITEM_THYSTAME);
    res[6] = get_item_count_in_tile(tile, ITEM_FOOD);
    return res;
}

int cmd_bct(server_t *server, char **command, int socket)
{
    int pos[2];
    int *count;

    if (strncmp("bct", command[0], 3) != 0) {
        return ERROR;
    }
    if (command[1] == NULL || command[2] == NULL) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    pos[X] = atoi(command[1]);
    pos[Y] = atoi(command[2]);
    tile_t *tile = get_tile_by_pos(pos, server->world);
    count = get_items_in_tile(tile);
    dprintf(socket, "bct %d %d %d %d %d %d %d %d %d\n", pos[X], pos[Y],
        count[0], count[1], count[2], count[3], count[4], count[5], count[6]);
    return SUCCESS;
}