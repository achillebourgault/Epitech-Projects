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

int cmd_look(server_t *server, char **command, int socket)
{
    player_t *player;

    if (strncmp("Look", command[0], 4) != 0) {
        return ERROR;
    }
    player = get_player_by_socket(server, socket);
    if (player->action > 0) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    if (player != NULL) {
        dprintf(socket, "%s\n", look_func(server, player));
        player->action = 7;
    } else
        perror("Player wasn't found [LOOK].\n");
    return SUCCESS;
}