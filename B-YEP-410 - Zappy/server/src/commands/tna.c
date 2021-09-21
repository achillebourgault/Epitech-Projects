/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include "../include/server.h"

int cmd_tna(server_t *server, char **command, int socket)
{
    int alloc = 1;
    char *request;

    if (strcmp("tna\n", command[0]) != 0) {
        return ERROR;
    }
    for (int i = 0; server->teams[i] != NULL; alloc += 5 +
    strlen(server->teams[i]->name), i++);
    request = safe_malloc(sizeof(char) * alloc);
    request[0] = '\0';
    for (int i = 0; server->teams[i] != NULL; i++) {
        strcat(request, "tna ");
        strcat(request, server->teams[i]->name);
        strcat(request, "\n");
    }
    dprintf(socket, "%s\n", request);
    return SUCCESS;
}