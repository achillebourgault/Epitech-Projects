/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"
#include <stdio.h>

void add_new_message(user_t *user, discussion_t *discussion, char **tab)
{
    int alloc = 0;
    messages_t **update;

    for (; discussion->messages[alloc] != NULL; alloc++);
    update = malloc(sizeof(messages_t *) * (alloc + 1));
    update[0] = create_message(tab[3], user->uuid, tab[2]);
    for (alloc = 0; discussion->messages[alloc] != NULL; alloc++)
        update[alloc + 1] = load_message(discussion->messages[alloc]->uuid);
    update[alloc] = NULL;
    discussion->messages = update;
    save_discussion(discussion);
}

void send_add_struct(char **tab, my_teams_t *teams)
{
    user_t *user = get_user_by_uuid(tab[1], teams->server->users);

    if (get_private_message_by_uuid(tab[1], tab[2],
        teams->server->discussion) == NULL &&
        get_private_message_by_uuid(tab[2], tab[1],
            teams->server->discussion) == NULL) {
        create_discussion(tab[1], tab[2], tab[3]);
    } else {
        discussion_t *dis = get_private_message_by_uuid(tab[1], tab[2],
        teams->server->discussion);

        if (dis == NULL)
            dis = get_private_message_by_uuid(tab[2], tab[1],
                teams->server->discussion);
        add_new_message(user, dis, tab);
    }
    load_data(teams);
}

int error_send(char *uuid, my_teams_t *teams)
{
    int nb = 0;

    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (strcmp(teams->server->users[i]->uuid, uuid) == 0)
            nb++;
    if (nb == 0)
        return 1;
    else
        return 0;
}

int cmd_send(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "300") != 0)
        return (1);
    if (error_send(tab[2], teams) == 1) {
        dprintf(socket, "311");
        return (0);
    }
    for (int i = 0; teams->server->users[i] != NULL; i++)
        if (strcmp(teams->server->users[i]->uuid, tab[2]) == 0 &&
            teams->server->users[i]->connected == 1) {
            dprintf(teams->server->users[i]->cli_sock, "800<SP>%s<SP>%s",
                tab[1], tab[3]);
            server_event_private_message_sended(tab[1], tab[2], tab[3]);
            dprintf(socket, "310");
        }
    send_add_struct(tab, teams);
    return (0);
}