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

void change_direction(player_t *player, int socket)
{
    if (player->vision->direction == NORTH) {
        player->vision->direction = WEST;
    } else if (player->vision->direction == WEST) {
        player->vision->direction = SOUTH;
    } else {
        if (player->vision->direction == SOUTH) {
            player->vision->direction = EAST;
        } else if (player->vision->direction == EAST) {
            player->vision->direction = NORTH;
        }
    }
    dprintf(socket, "ok\n");
}

int cmd_left(server_t *server, char **command, int socket)
{
    player_t *player = NULL;

    if (strncmp("Left", command[0], 4) != 0)
        return ERROR;
    player = get_player_by_socket(server, socket);
    if (player->action > 0) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    if (player != NULL) {
        change_direction(player, socket);
        player->action = 7;
    } return SUCCESS;
}