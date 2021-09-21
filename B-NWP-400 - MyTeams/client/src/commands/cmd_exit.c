/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <string.h>
extern int exit_client;

int cmd_exit(client_t *client, char **command)
{
    if (strcmp(command[0], "/exit") != 0)
        return ERROR;
    exit_client = 1;
    return SUCCESS;
}