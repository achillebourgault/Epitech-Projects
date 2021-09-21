/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"
#include <stdio.h>

char *compress(my_teams_t *teams)
{
    char *to_ret = NULL;
    int nb = 3;

    for (int i = 0; teams->server->users[i] != NULL; i++)
        nb += 13 + strlen(teams->server->users[i]->name) +
            strlen(teams->server->users[i]->uuid);
    to_ret = malloc(sizeof(char) * (nb + 1));
    to_ret[0] = '\0';
    to_ret = strcat(to_ret, "210");
    for (int i = 0; teams->server->users[i] != NULL; i++) {
        to_ret = strcat(to_ret, "<SP>");
        to_ret = strcat(to_ret, teams->server->users[i]->name);
        to_ret = strcat(to_ret, "<sp>");
        to_ret = strcat(to_ret, teams->server->users[i]->uuid);
        to_ret = strcat(to_ret, "<sp>");
        to_ret = strcat(to_ret,
            teams->server->users[i]->connected == 1 ? "1" : "0");
    }
    return to_ret;
}

int cmd_users(char *buffer, my_teams_t *teams, int socket)
{
    char *str = compress(teams);
    if (strcmp(buffer, "200") != 0)
        return (1);
    dprintf(socket, "%s", str);
    return (0);
}

int count_user(my_teams_t *teams, char *uuid)
{
    int nb;
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (strcmp(teams->server->users[i]->uuid, uuid) == 0)
            nb = nb + strlen(teams->server->users[i]->name) +
                strlen(teams->server->users[i]->uuid);
    return nb;
}

char *compress_user(my_teams_t *teams, char *uuid)
{
    char *to_ret = NULL;
    int nb = 16;
    int i = 0;

    nb += count_user(teams, uuid);
    to_ret = malloc(sizeof(char) * (nb + 1));
    to_ret[0] = '\0';
    to_ret = strcat(to_ret, "260");
    for (i = 0, nb = 0; teams->server->users[i] != NULL; i++)
        if (strcmp(teams->server->users[i]->uuid, uuid) == 0) {
            to_ret = strcat(to_ret, "<SP>");
            to_ret = strcat(to_ret, teams->server->users[i]->name);
            to_ret = strcat(to_ret, "<sp>");
            to_ret = strcat(to_ret, teams->server->users[i]->uuid);
            to_ret = strcat(to_ret, "<sp>");
            to_ret = strcat(to_ret,
                teams->server->users[i]->connected == 1 ? "1" : "0");
            nb++;
        }
    return (nb <= 0 ? strdup("261") : to_ret);
}

int cmd_user(char *buffer, my_teams_t *teams, int socket)
{
    char *str = NULL;
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "250") != 0)
        return (1);
    str = compress_user(teams, tab[1]);
    dprintf(socket, "%s", str);
    return 0;
}