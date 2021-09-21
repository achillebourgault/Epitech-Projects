/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../include/server.h"
#include <string.h>

int cmd_pbc(server_t *server, char **command, int socket)
{
    if (strcmp("pbc", command[0]) || command[0] == NULL)
    {
        return ERROR;
    }

}