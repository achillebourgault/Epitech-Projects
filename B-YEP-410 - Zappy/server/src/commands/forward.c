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

int cmd_forward(server_t *server, char **command, int socket)
{
    player_t *player;

    if (strncmp("Forward", command[0], 7) != 0)
        return ERROR;
    player = get_player_by_socket(server, socket);
    if (player->action == 0) {
        if (player != NULL) {
            move(server, player, player->vision->direction);
            dprintf(socket, "ok\n");
            player->action = 7;
        }
    } else {
        dprintf(socket, "ko\n");
    }
    return SUCCESS;
}