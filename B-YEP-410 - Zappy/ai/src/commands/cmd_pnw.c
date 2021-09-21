/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"

int cmd_pnw(client_t *client)
{
    char *server_reply;

    dprintf(client->socket, "pnw %s\n", client->team_name);
    server_reply = read_request(client->socket);
    if (strcmp(server_reply, "ko\n") == 0) {
        printf("Invalid team or to many players connected in the team\n");
        exit(84);
    }
}