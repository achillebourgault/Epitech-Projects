/*
** EPITECH PROJECT, 2024
** myteams_server
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../../include/myteams_client.h"
#include <string.h>

int event_login_error_handling(client_t *client, char **command)
{
    if (strcmp(command[0], "810") != 0)
        return ERROR;
    if (command[1] == NULL)
        return SUCCESS;
    if (command[2] == NULL)
        return SUCCESS;
    return 0;
}

int event_login(client_t *client, char **command)
{
    int error_handling = event_login_error_handling(client, command);

    if (error_handling != 0)
        return error_handling;
    client_event_logged_in(command[2], command[1]);
    return SUCCESS;
}