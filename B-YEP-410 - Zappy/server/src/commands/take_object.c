/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <stdio.h>
#include <string.h>

int cmd_take_object(server_t *server, char **command, int socket)
{
    player_t *player = get_player_by_socket(server, socket);
    tile_t *tile = get_tile_by_pos(player->pos, server->world);
    item_t *choosed = NULL;
    int x;

    if (strncmp("Take", command[0], 4) != 0) return ERROR;
    if (command[1] == NULL || player->action > 0) {
        dprintf(socket, "ko\n"); return SUCCESS;
    }
    command[1] = clean_str(command[1], '\n');
    for (x = 0; tile->items[x] != NULL &&
    tile->items[x]->type != get_id_by_name(command[1]); x++);
    if (tile->items[x] != NULL && tile->items[x]->type ==
    get_id_by_name(command[1])) {
        add_item_to_inventory(player, tile->items[x]->type, 1);
        remove_ressource_to_tile(tile->items[x], tile);
        dprintf(socket, "ok\n");
    }
    else
        dprintf(socket, "ko\n");
    player->action = 7; return SUCCESS;
}