/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"
#include <stdio.h>

int cmd_login_verif_if_existing(my_teams_t *teams, int i, char **tab,
    int socket)
{

    if (strcmp(teams->server->users[i]->name, tab[1]) == 0) {
        teams->server->users[i]->connected = 1;
        save_user(teams->server->users[i]);
        dprintf(socket, "110<SP>%s", teams->server->users[i]->uuid);
        server_event_user_logged_in(teams->server->users[i]->uuid);
        return (0);
    }
    return (1);
}

void send_login_events(my_teams_t *teams, user_t *user)
{
    for (int i = 0; teams->server->users[i] != NULL; i++) {
        if (teams->server->users[i]->connected == 1 &&
        teams->server->users[i]->uuid != user->uuid)
            dprintf(teams->server->users[i]->cli_sock,"810<SP>%s<SP>%s", user->name, user->uuid);
    }
}

int cmd_login(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "100") != 0)
        return (1);
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (cmd_login_verif_if_existing(teams, i, tab, socket) != 1)
            return 0;
    create_user(tab[1], socket);
    load_data(teams);
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (strcmp(teams->server->users[i]->name, tab[1]) == 0 &&
            teams->server->users[i]->connected == 0) {
            teams->server->users[i]->connected = 1;
            save_user(teams->server->users[i]);
            dprintf(socket, "110<SP>%s", teams->server->users[i]->uuid);
            server_event_user_created(teams->server->users[i]->uuid,
                teams->server->users[i]->name);
            server_event_user_logged_in(teams->server->users[i]->uuid);
            send_login_events(teams, teams->server->users[i]); break;
        }
    return 0;
}

void send_logout_events(my_teams_t *teams, user_t *user)
{
    for (int i = 0; teams->server->users[i] != NULL; i++) {
        if (teams->server->users[i]->connected == 1 &&
            teams->server->users[i]->uuid != user->uuid)
            dprintf(teams->server->users[i]->cli_sock,"811<SP>%s<SP>%s", user->name, user->uuid);
    }
}

int cmd_logout(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "150") != 0)
        return (1);
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (strcmp(teams->server->users[i]->uuid, tab[1]) == 0) {
            teams->server->users[i]->connected = 0;
            save_user(teams->server->users[i]);
            server_event_user_logged_out(teams->server->users[i]->uuid);
            dprintf(socket, "160");
            send_logout_events(teams, teams->server->users[i]);
            return (0);
        }
    return (0);
}