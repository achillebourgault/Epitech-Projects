/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include <stdio.h>
#include "../include/server.h"

int cmd_msz(server_t *server, char **command, int socket)
{
    if (strcmp("msz", command[0]) != 0) {
        return ERROR;
    }
    if (command[1] == NULL || command[2] == NULL) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }

    dprintf(socket, "msz %d %d\n", server->world->dimensions[X],
        server->world->dimensions[Y]);
    return SUCCESS;
}