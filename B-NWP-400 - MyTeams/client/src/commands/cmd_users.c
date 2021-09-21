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

int users_error_handling(client_t *client, char **command)
{
    char *username;

    if (strcmp(command[0], "/users") != 0)
        return ERROR;
    if (client->connected == 0) {
        client_error_unauthorized();
        return SUCCESS;
    }
    return 0;
}

void handle_users_reply(client_t *client, char **reply)
{
    char **user;
    int status = -42;
    char *endptr;

    if (strcmp(reply[0], "210") == 0) {
        for (int i = 1; reply[i] != NULL; i++) {
            user = malloc(sizeof(*user) * 3);
            user = str_to_word_array(reply[i], "<sp>");
            status = atoi(user[2]);
            client_print_users(user[1], user[0], status);
        }
    }
}

int cmd_users(client_t *client, char **command)
{
    int error_handling = users_error_handling(client, command);
    char **reply;

    if (strcmp(command[0], "/users") != 0)
        return ERROR;
    if (error_handling != 0)
        return error_handling;
    send_request(client, "200", NULL);
    reply = get_request(client);
    handle_users_reply(client, reply);
    for (int i = 0; reply[i] != NULL; i++)
        free(reply[i]);
    free(reply);
    return SUCCESS;
}