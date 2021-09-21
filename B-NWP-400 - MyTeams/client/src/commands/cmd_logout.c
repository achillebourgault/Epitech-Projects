/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>

extern int exit_client;

void handle_logout_request(client_t *client, char **reply)
{
    if (reply == NULL)
        return;
    if (strcmp(reply[0], "160") == 0) {
        client_event_logged_out(client->user_uid, client->username);
    }
}

char **create_logout_arglist(char *uid)
{
    char **arg_list = malloc(sizeof(*arg_list) * 2);

    arg_list[0] = strdup(uid);
    arg_list[1] = NULL;
    return arg_list;
}

int cmd_logout(client_t *client, char **command)
{
    if (strcmp(command[0], "/logout") != 0)
        return ERROR;
    if (client->connected == 0) {
        client_error_unauthorized();
        return SUCCESS;
    }
    exit_client = 1;
    return SUCCESS;
}