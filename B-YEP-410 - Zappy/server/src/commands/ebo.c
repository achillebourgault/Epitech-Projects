/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>

int cmd_ebo(server_t *server, char **command, int socket)
{
    if (strcmp("ebo", command[0]) != 0 || command[0] == NULL) {
        return ERROR;
    }
    return ERROR;
}