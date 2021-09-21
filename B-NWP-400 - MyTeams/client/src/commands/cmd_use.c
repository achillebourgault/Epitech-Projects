/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <stdio.h>
#include <string.h>

int use_error_handling(client_t *client, char **command)
{
    int i = 1;

    if (strcmp(command[0], "/use") != 0)
        return ERROR;
    if (client->connected == 0) {
        client_error_unauthorized();
        return SUCCESS;
    }
    for (i = 1; command[i] != NULL; i++);
    i--;
    if (i <= 0 || i > 3)
        return SUCCESS;
    return 0;
}

void fill_use(client_t *client, char *const *command, int arg_count)
{
    int i = 0;
    int j = 1;

    for (i = 0; i != 3; i++) {
        client->use[i] = NULL;
    }
    for (i = 0; i != arg_count; i++, j++) {
        if (command[j] != NULL) {
            client->use[i] = strdup(command[j]);
        }
        else client->use[i] = NULL;
    }
}

int cmd_use(client_t *client, char **command)
{

    int error_handling = use_error_handling(client, command);
    int arg_count = 1;

    if (error_handling != 0)
        return error_handling;
    for (arg_count = 1; command[arg_count] != NULL; arg_count++);
    arg_count--;
    fill_use(client, command, arg_count);
    return SUCCESS;
}