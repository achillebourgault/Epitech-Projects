/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include "../include/server.h"

int vzr_lgn(server_t *server, int socket)
{
    int team_count = 0;

    printf("Visualizer connected\n");
    for (team_count = 0; server->teams[team_count] != NULL; team_count++);
    dprintf(socket, "vzr_lgn<SP>%d %d<SP>%d<SP>%d\n",
        server->world->dimensions[X],
        server->world->dimensions[Y], team_count,
        server->config->max_players_team);
    return SUCCESS;
}