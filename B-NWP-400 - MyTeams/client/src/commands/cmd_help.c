/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frederic LAWECKI--WALKOWIAK
*/

#include "../../include/myteams_client.h"
#include <stdio.h>
#include <string.h>

int cmd_help(client_t *client, char **command)
{
    if (strcmp(command[0], "/help") != 0)
        return ERROR;
    printf("MyTeams Client, Epitech Project\nAvailable commands:\n");
    printf("\t/help\n");
    printf("\t/login \"[username]\"\n");
    printf("\t/logout\n");
    printf("\t/users\n");
    printf("\t/user \"[user_uuid]\"\n");
    printf("\t/send \"[user_uuid]\" \"[message_body]\"\n");
    printf("\t/messages \"[user_uuid]\"\n");
    printf("\t/subscribe \"[team_uuid]\"\n");
    printf("\t/subscribed ?\"[team_uuid]\"\n");
    printf("\t/unsubscribe \"[team_uuid]\"\n");
    printf("\t/use ?\"[team_uuid]\" ?\"[channel_uuid]\" ?\"[thread_uuid]\"\n");
    printf("\t/create\n");
    printf("\t/list\n");
    printf("\t/info\n");
    return SUCCESS;
}