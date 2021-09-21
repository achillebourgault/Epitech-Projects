/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <unistd.h>
#include "../include/server.h"

void interpret_command(char *command, client_t *client, myftp_t *ftp,
    int (*commands[15])(char *, client_t *, myftp_t *))
{
    for (int i = 0; i < 15; i++) {
        if ((commands[i](command, client, ftp)) == 0)
            break;
    }
}

void handle_commands(myftp_t *ftp, client_t *client)
{
    char command[256];
    int read_ret;
    int (*commands[15])(char *, client_t *, myftp_t *) = {command_execute_cdup,
        command_execute_cwd, command_execute_dele, command_execute_help,
        command_execute_list, command_execute_noop, command_execute_passwd,
        enable_passive_mode, enable_active_mode, command_execute_pwd,
        command_execute_quit, command_execute_retr, command_execute_stor,
        command_execute_user, unknown_command};

    if (client != NULL && client->connected == 0) {
        read_ret = read(client->client_socket, command, 256);
        command[read_ret] = '\0';
        if (read_ret > 0) {
            interpret_command(command, client, ftp, commands);
        }
    }
}