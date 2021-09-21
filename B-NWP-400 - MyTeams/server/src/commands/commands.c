/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"

int unknown_command(char *buffer, my_teams_t *teams, int socket)
{
    return 0;
}

void interpret_command(char *command, my_teams_t *teams,
    int (*commands[21])(char *, my_teams_t *, int), int socket)
{
    for (int i = 0; i < 24; i++) {
        if ((commands[i](command, teams, socket)) == 0)
            break;
    }
}

void handle_commands(my_teams_t *teams, int socket, char *buffer)
{
    int (*commands[24])(char *, my_teams_t *, int) = {cmd_help,
        cmd_create_teams, cmd_create_channel, cmd_create_threads,
        cmd_create_reply, cmd_info_logged, cmd_info_team, cmd_info_channel,
        cmd_info_thread, cmd_list_teams, cmd_list_channels, cmd_list_threads,
        cmd_list_replies, cmd_login, cmd_logout, cmd_messages, cmd_send,
        cmd_subscribe, cmd_subscribed, cmd_unsubscribe, cmd_use, cmd_user,
        cmd_users, unknown_command};

    if (strlen(buffer) > 0)
        interpret_command(buffer, teams, commands, socket);
}