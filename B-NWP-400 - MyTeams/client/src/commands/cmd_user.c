/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <string.h>
#include <stdlib.h>

int user_error_handling(client_t *client, char **command)
{
    if (strcmp(command[0], "/user") != 0)
        return ERROR;
    if (command[1] == NULL)
        return SUCCESS;
    if (client->connected == 0) {
        client_error_unauthorized();
        return SUCCESS;
    }
    return 0;
}

char **create_user_arglist(char *uid)
{
    char **arg_list = malloc(sizeof(*arg_list) * 2);

    arg_list[0] = strdup(uid);
    arg_list[1] = NULL;
    return arg_list;
}

void handle_user_reply(client_t *client, char **reply, char *uid)
{
    char **user;
    int status;

    if (strcmp(reply[0], "260") == 0) {
        user = malloc(sizeof(*user) * 3);
        user = str_to_word_array(reply[1], "<sp>");
        status = atoi(user[2]);
        client_print_user(user[1], user[0], status);
    } else if (strcmp(reply[0], "261") == 0) {
        client_error_unknown_user(uid);
    }
}

int cmd_user(client_t *client, char **command)
{
    int error_handling = user_error_handling(client, command);
    char **arglist;
    char **reply;

    if (error_handling != 0)
        return error_handling;
    clean_str(command[1], '\"');
    arglist = create_user_arglist(command[1]);
    send_request(client, "250", arglist);
    reply = get_request(client);
    handle_user_reply(client, reply, command[1]);
    for (int i = 0; arglist[i] != NULL; i++)
        free(arglist[i]);
    for (int i = 0; reply[i] != NULL; i++)
        free(reply[i]);
    free(arglist);
    free(reply);
    return SUCCESS;
}