/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>

int cmd_edi(server_t *server, char **command, int socket)
{
    if (strcmp("edi", command[0]) != 0)
        return ERROR;
    else if (command[0] == NULL)
        return ERROR;
    else
        return SUCCESS;
}