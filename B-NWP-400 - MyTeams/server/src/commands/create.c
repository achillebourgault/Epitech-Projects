/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"
#include <stdio.h>

int cmd_create_teams(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");
    char *uuid = NULL;

    if (strcmp(tab[0], "600") != 0)
        return (1);
    uuid = strdup(create_team(tab[1], tab[3], tab[2])->uuid);
    load_data(teams);
    dprintf(socket, "605<SP>%s", uuid);
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (teams->server->users[i]->connected == 1
        && teams->server->users[i]->cli_sock != socket)
            dprintf(teams->server->users[i]->cli_sock, "801<SP>%s<SP>%s<SP>%s"
                    , tab[1], tab[2], uuid);
    return (0);
}

int cmd_create_channel(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");
    char *uuid = NULL;

    if (strcmp(tab[0], "610") != 0)
        return (1);
    uuid = strdup(create_channel(tab[1], tab[3], tab[2])->uuid);
    load_data(teams);
    dprintf(socket, "615<SP>%s", uuid);
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (teams->server->users[i]->connected == 1
            && teams->server->users[i]->cli_sock != socket)
            dprintf(teams->server->users[i]->cli_sock, "801<SP>%s<SP>%s<SP>%s"
                    , tab[1], tab[2], uuid);
    return (0);
}

int cmd_create_threads(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "620") != 0)
        return (1);
    return (1);
}

int cmd_create_reply(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "630") != 0)
        return (1);
    return (1);
}