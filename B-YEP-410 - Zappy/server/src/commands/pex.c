/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>
#include <stdio.h>

int cmd_pex(server_t *server, char **command, int socket)
{
    if (strcmp("pex", command[0]) != 0  || command[1] != NULL)
    return ERROR;

    else
        server->player->pos[2] = server->player->pos[0];
        dprintf(socket, "ok\n");
    return SUCCESS;
}