/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <stdio.h>

int cmd_unknown(client_t *client, char **command)
{
    printf("Error: unknown command\n");
    return SUCCESS;
}