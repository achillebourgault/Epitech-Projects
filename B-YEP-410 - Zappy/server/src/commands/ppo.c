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

int cmd_ppo(server_t *server, char **command, int socket)
{
    player_t *p;
    int index;

    if (strcmp("ppo", command[0]) != 0 || command[1] == NULL)
        return ERROR;
    index = atoi(strtok(command[1], "#"));
    p = get_player_by_index(get_all_players(server), index);
    if (p == NULL) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    dprintf(socket, "ppo %d %d %d %d\n",
        index,
        p->pos[X],
        p->pos[Y],
        p->vision->direction);
    return SUCCESS;
}