/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>
#include <stdio.h>

int cmd_pie(server_t *server, char **command, int socket)
{
    if (strncmp("pie", command[0], 3) != 0 || command[1] == NULL)
        return ERROR;
    if (command[1] == NULL || command[2] == NULL) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    return SUCCESS;
}