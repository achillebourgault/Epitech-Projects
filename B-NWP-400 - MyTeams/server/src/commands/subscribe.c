/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include "../../include/my_teams.h"

int cmd_subscribe(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "100") != 0)
        return 1;
    for (int i = 0; teams->server->teams[i] != NULL; i++) {
        if (strcmp(teams->server->teams[i]->uuid, tab[1]) == 0) {
            add_new_subscriber(teams->server->teams[i], tab[2]);
            dprintf(socket, "410");
            server_event_user_subscribed(teams->server->teams[i]->uuid, tab[2]);
            return 0;
        }
    }
    dprintf(socket, "411");
    return 0;
}

int cmd_subscribed(char *buffer, my_teams_t *teams, int socket)
{
    return 1;
}

int cmd_unsubscribe(char *buffer, my_teams_t *teams, int socket)
{
    return 1;
}