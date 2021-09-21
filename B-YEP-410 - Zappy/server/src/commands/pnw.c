/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include "../include/server.h"
#include <stdio.h>

int login_player(server_t *server, char *team_name, int socket)
{
    player_t *player;
    team_t *team;
    int clientnum = 0;
    char *name;

    name = clean_str(team_name, '\n');
    player = create_player(socket, server->world->dimensions, server);
    team = get_team_by_name(server, name);
    if (team == NULL) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    for (int i = 0; team->players[i] != NULL; i++, clientnum++);
    clientnum = server->config->max_players_team - clientnum;
    dprintf(socket, "%d\n", clientnum);
    dprintf(socket, "%d %d\n", server->world->dimensions[X],
    server->world->dimensions[Y]);
    printf("%d\n%d %d\n", clientnum, server->world->dimensions[X],
    server->world->dimensions[Y]);
    join_team(server, player, team);
    return SUCCESS;
}