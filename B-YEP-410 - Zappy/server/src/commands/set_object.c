/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>
#include <stdio.h>

int cmd_set_object(server_t *server, char **command, int socket)
{
    player_t *player;
    tile_t *tile;
    item_t *choosed = NULL;
    int x;

    if (strncmp("Set", command[0], 3) != 0)
        return ERROR;
    player = get_player_by_socket(server, socket);
    if (command[1] == NULL || player->action > 0 ||
    player_contains_at_least(player, get_id_by_name(command[1]), 1) == FALSE) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    player->action = 7;
    command[1] = clean_str(command[1], '\n');
    tile = get_tile_by_pos(player->pos, server->world);
    use_item(player, get_id_by_name(command[1]), 1);
    add_ressource_to_tile(create_item(get_id_by_name(command[1])), tile);
    dprintf(socket, "ok\n");
    return SUCCESS;
}