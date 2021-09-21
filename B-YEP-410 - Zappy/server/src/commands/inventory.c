/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmd_inventory(server_t *server, char **command, int socket)
{
    player_t *player = NULL;
    char *str = NULL;

    if (strncmp("Inventory", command[0], 9) != 0)
        return ERROR;
    player = get_player_by_socket(server, socket);
    if (player->action > 0) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    str = get_inventory_data(player);
    player->action = 1;
    dprintf(socket, "%s\n", str);
    return SUCCESS;
}