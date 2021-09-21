/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login_error_handling(client_t *client, char **command)
{
    char *username;

    if (strcmp(command[0], "/login") != 0)
        return ERROR;
    if (client->connected == 1)
        return SUCCESS;
    if (command[1] == NULL) {
        printf("Error: you need to specify a username.\n");
        return SUCCESS;
    }
    username = strdup_bounds(command[1], 1, strlen(command[1]) - 1);
    if (strlen(username) > MAX_NAME_LENGTH) {
        printf("Error: too long username\n");
        free(username);
        return SUCCESS;
    }
    return 0;
}

void handle_login_reply(client_t *client, char **reply)
{
    if (reply == NULL)
        return;
    if (strcmp(reply[0], "110") == 0) {
        client->user_uid = strdup(reply[1]);
        client_event_logged_in(client->user_uid, client->username);
        client->connected = 1;
    }
    if (strcmp(reply[0], "111") == 0) {
        printf("Error: user already logged in on an other client\n");
    }
}

char **create_login_arglist(char *username)
{
    char **arg_list = malloc(sizeof(*arg_list) * 2);

    arg_list[0] = strdup(username);
    arg_list[1] = NULL;
    return arg_list;
}

int cmd_login(client_t *client, char **command)
{
    int error_handling = login_error_handling(client, command);
    char **arg_list;
    char **reply;

    if (error_handling != 0)
        return error_handling;
    client->username = strdup_bounds(command[1], 1,
        strlen(command[1]) - 1);
    arg_list = create_login_arglist(client->username);
    send_request(client, "100", arg_list);
    reply = get_request(client);
    handle_login_reply(client, reply);
    for (int i = 0; arg_list[i] != NULL; i++)
        free(arg_list[i]);
    for (int i = 0; reply[i] != NULL; i++)
        free(reply[i]);
    free(arg_list);
    free(reply);
    return SUCCESS;
}