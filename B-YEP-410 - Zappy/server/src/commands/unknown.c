/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include "../include/server.h"

int cmd_unknown(server_t *server, char **command, int socket)
{
    dprintf(socket, "ko\n");
    return SUCCESS;
}