/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmd_connect_nbr(server_t *server, char **command, int socket)
{
    int nb = 0;
    int ret = 0;

    if (strcmp("Connect_nbr", command[0]) != 0)
        return ERROR;
    for (int i = 0; server->teams[i] != NULL; i++) {
        if (server->teams[i]->id != 0) {
            nb++;
        }
    }
    ret = CONFIG_MAX_TEAMS - nb;
    dprintf(socket, "%i\n", ret);
    return SUCCESS;
}