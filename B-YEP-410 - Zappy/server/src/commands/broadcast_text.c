/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>

int cmd_broadcast_text(server_t *server, char **command, int socket)
{
    player_t *player = NULL;

    if (strncmp("Broadcast", command[0], 9) != 0)
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