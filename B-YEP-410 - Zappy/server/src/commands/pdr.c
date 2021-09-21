/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>

int cmd_pdr(server_t *server, char **command, int socket)
{
    if (strcmp("pdr", command[0]) != 0)
    {
        return ERROR;
    }

    return ERROR;
}