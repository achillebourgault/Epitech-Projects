/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cmd_incantation(server_t *server, char **command, int socket)
{
    player_t *player = NULL;

    if (strncmp("Incantation", command[0], 11) != 0)
        return ERROR;
    player = get_player_by_socket(server, socket);
    if (player->action > 0) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    player->action = 300;
    dprintf(socket, "ok\n");
    return SUCCESS;
}