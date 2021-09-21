/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SFML/Graphics/Color.h>
#include "../include/server.h"

int get_team_color(server_t *server)
{
    int res;

    res = (rand() % (255 - 0 + 1)) + 0;
    return res;
}

char send_plrz_request(server_t *server, int socket, int alloc)
{
    char *request = safe_malloc(sizeof(char) * alloc);
    char const *tmp_team_name;
    player_t **all = get_all_players(server);
    char tmp[20];

    request[0] = '\0'; strcat(request, "vzr_plrs<SP>");
    strcat(request, my_itoa(get_total_players(server)));
    strcat(request, "<SP>");
    for (int p_count = 0; all[p_count] != NULL; p_count++) {
        tmp_team_name = get_team_by_player(server, all[p_count])->name;
        sprintf(tmp, "%d<sp>%d", all[p_count]->pos[X], all[p_count]->pos[Y]);
        strcat(request, tmp); strcat(request, "<sp>");
        strcat(request, my_itoa(all[p_count]->level)); strcat(request, "<sp>");
        strcat(request, tmp_team_name); strcat(request, "<sp>");
        sprintf(tmp, "%d<sp>%d<sp>%d", get_team_by_player(server,
        all[p_count])->color[0], get_team_by_player(server,
        all[p_count])->color[1], get_team_by_player(server,
        all[p_count])->color[2]);
        strcat(request, tmp); strcat(request, "<SP>");
    }
    dprintf(socket, "%s\n", request);
}

int cmd_vzr_plrs(server_t *server, char **command, int socket)
{
    int p_count = 0;
    int alloc = 15;
    player_t **all = get_all_players(server);
    char const *tmp_team_name;

    if (strncmp("vzr_plrs", command[0], 8) != 0) return ERROR;
    alloc += strlen(my_itoa(get_total_players(server))) + 4;
    for (p_count = 0; all[p_count] != NULL; p_count++) {
        tmp_team_name = get_team_by_player(server, all[p_count])->name;
        alloc += strlen(tmp_team_name) + strlen(my_itoa(all[p_count]->pos[X])) +
            strlen(my_itoa(all[p_count]->pos[Y])) +
            strlen(my_itoa(all[p_count]->level)) + 20 + strlen(
            my_itoa(get_team_by_player(server, all[p_count])->color[0])) +
            strlen(
                my_itoa(get_team_by_player(server, all[p_count])->color[1])) +
            strlen(
                my_itoa(get_team_by_player(server, all[p_count])->color[2])) +
            +23;
    }
    send_plrz_request(server, socket, alloc); return SUCCESS;
}