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

int send_error_handling(client_t *client, char **command)
{
    if (strcmp(command[0], "/send") != 0)
        return ERROR;
    if (command[1] == NULL)
        return SUCCESS;
    if (command[2] == NULL)
        return SUCCESS;
    if (strlen(command[2]) > (MAX_BODY_LENGTH + 2))
        printf("Too long message\n");
    if (client->connected == 0) {
        client_error_unauthorized();
        return SUCCESS;
    }
    return 0;
}

char **create_send_arglist(
    char *sender_uid, char *recipient_uid, char *message
)
{
    char **arg_list = malloc(sizeof(*arg_list) * 4);

    clean_str(recipient_uid, '"');
    clean_str(message, '"');
    arg_list[0] = strdup(sender_uid);
    arg_list[1] = strdup(recipient_uid);
    arg_list[2] = strdup(message);
    arg_list[3] = NULL;
    return arg_list;
}

void handle_send_reply(
    client_t *client, char **reply, char *message, char *recipient
)
{
    if (strcmp(reply[0], "310") == 0) {
        return;
    } else if (strcmp(reply[0], "311") == 0) {
        client_error_unknown_user(recipient);
    }
}

int cmd_send(client_t *client, char **command)
{
    int error_handling = send_error_handling(client, command);
    char **arglist;
    char **reply;

    if (error_handling != 0)
        return error_handling;
    arglist = create_send_arglist(client->user_uid, command[1], command[2]);
    send_request(client, "300", arglist);
    reply = get_request(client);
    handle_send_reply(client, reply, command[2], command[1]);
    for (int i = 0; arglist[i] != NULL; i++)
        free(arglist[i]);
    for (int i = 0; reply[i] != NULL; i++)
        free(reply[i]);
    free(arglist);
    free(reply);
    return SUCCESS;
}