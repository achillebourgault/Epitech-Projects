/*
** EPITECH PROJECT, 2024
** myteams_server
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "../../include/myteams_client.h"
#include <string.h>

int pm_error_handling(client_t *client, char **command)
{
    if (strcmp(command[0], "800") != 0)
        return ERROR;
    if (command[1] == NULL)
        return SUCCESS;
    if (command[2] == NULL)
        return SUCCESS;
    return 0;
}

int event_private_msg(client_t *client, char **command)
{
    int error_handling = pm_error_handling(client, command);

    if (error_handling != 0)
        return error_handling;
    client_event_private_message_received(command[1], command[2]);
    return SUCCESS;
}