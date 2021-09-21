/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/server.h"

server_t *init_server(parser_t *parser)
{
    server_t *res = safe_malloc(sizeof(server_t));

    res->port = parser->port;
    res->quit = 0;
    res->config = safe_malloc(sizeof(config_t));
    res->config->max_players_team = parser->clientsNb;
    res->config->freq = parser->freq;
    res->world = generate_world((int[2]){parser->width, parser->height});
    res->sock_array = malloc(sizeof(int) * FD_SETSIZE);
    for (int i = 0; parser->team_names[i] != NULL; i++)
        create_team(res, parser->team_names[i], i);
    generate_ressources(res->world);
    if (init_network(res) == ERROR) {
        exit(84);
    }
    return res;
}

void broadcast(player_t **players, char *message)
{
    if (players == NULL) {
        printf("Broadcast Error: Target is NullPointer.");
        return;
    }
    for (int i = 0; players[i] != NULL; i++)
        dprintf(players[i]->socket, "%s\n", message);
}