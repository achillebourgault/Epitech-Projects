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

int cmd_eject(server_t *server, char **command, int socket)
{
    player_t *player = NULL;

    if (strncmp("Eject", command[0], 5) != 0)
        return ERROR;
    player = get_player_by_socket(server, socket);
    if (player->action > 0) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    player->action = 7;
    dprintf(socket, "ok\n");
    return SUCCESS;
}