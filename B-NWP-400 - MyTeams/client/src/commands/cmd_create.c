/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <stdio.h>
#include <string.h>

int cmd_create(client_t *client, char **command)
{
    if (strcmp(command[0], "/create") != 0)
        return ERROR;
    if (client->connected == 0) {
        client_error_unauthorized();
        return SUCCESS;
    }
    return SUCCESS;
}