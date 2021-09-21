/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>

int cmd_suc(server_t *server, char **command, int socket)
{
    if (strcmp("suc", command[0]) != 0 || command[1] == NULL)
        return ERROR;
    return SUCCESS;
}