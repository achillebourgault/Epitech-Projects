/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <stdio.h>
#include <string.h>

void handle_command(client_t *client, char **request)
{
    int (*functionptr[COMMAND_COUNT])(client_t *, char **) = {cmd_use, cmd_exit,
        cmd_help, cmd_info, cmd_list, cmd_send, cmd_user, cmd_login, cmd_users,
        cmd_create, cmd_logout, cmd_messages, cmd_subscribe, cmd_subscribed,
        cmd_unsubscribe, cmd_unknown};

    for (int i = 0; i != COMMAND_COUNT; i++) {
        if (functionptr[i](client, request) == SUCCESS)
            break;
    }
}

void handle_request(client_t *client, char **command_array)
{
    int (*functionptr[EVENTS_COUNT])(client_t *, char **) = {event_private_msg,
        event_login, event_logout, event_unknown};

    for (int i = 0; i != EVENTS_COUNT; i++) {
        if (functionptr[i](client, command_array) == SUCCESS)
            break;
    }
}