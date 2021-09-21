/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <string.h>
#include <printf.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/server.h"

void create_team(server_t *server, char *name, int id)
{
    team_t *res = safe_malloc(sizeof(team_t));

    res->id = id;
    res->name = strdup(name);
    res->players = safe_malloc(
        sizeof(player_t *) * (server->config->max_players_team + 1));
    res->players[0] = NULL;
    res->color[0] = get_team_color(server);
    res->color[1] = get_team_color(server);
    res->color[2] = get_team_color(server);
    server->teams[res->id] = res;
    server->teams[res->id + 1] = NULL;
}

void join_team(server_t *server, player_t *player, team_t *team)
{
    int id = 0;

    if (team == NULL)
        exit(42);
    for (; team->players[id] != NULL; id++);
    if (id > server->config->max_players_team) {
        printf("Error: Team is full [teamId: %s]\n", team->name);
        return;
    }
    team->players[id] = player;
    team->players[id + 1] = NULL;
    printf("Player %d of team %s has login\n", id, team->name);
}

team_t *get_team_by_player(server_t *server, player_t *p)
{
    for (int i = 0; server->teams[i] != NULL; i++) {
        for (int x = 0; server->teams[i]->players[x] != NULL; x++) {
            if (server->teams[i]->players[x] == p)
                return server->teams[i];
        }
    }
    return NULL;
}

team_t *get_team_by_name(server_t *server, char *name)
{
    size_t name_length = 0;

    for (int i = 0; server->teams[i] != NULL; i++) {
        name_length = strlen(server->teams[i]->name);
        if (strncmp(name, server->teams[i]->name, name_length) == 0) {
            return server->teams[i];
        }
    }
    return NULL;
}