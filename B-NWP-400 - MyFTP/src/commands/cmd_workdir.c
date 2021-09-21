/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../../include/server.h"

int command_execute_cwd(char *command, client_t *client, myftp_t *ftp)
{
    int res = 0;

    if (strncmp(command, "CWD ", 4) != 0)
        return 84;
    command = strtok(command, "CWD ");
    command = strtok(command, "\n\r");
    client->working_directory = strdup(command);
    return res;
}

int command_execute_cdup(char *command, client_t *client, myftp_t *ftp)
{
    int res = 0;

    if (strncmp(command, "CDUP", 4) != 0)
        return 84;
    if (is_connected(client, 0) != 0)
        return 84;
    client->working_directory = client->parent_directory;
    return res;
}

int command_execute_pwd(char *command, client_t *client, myftp_t *ftp)
{
    int res = 0;
    int status = 257;
    char pwd[PATH_MAX];

    if (strncmp(command, "PWD", 3) != 0)
        return 84;
    if (is_connected(client, 0) != 0)
        return 84;
    dprintf(client->client_socket, "%d \"%s\"\n", status,
        realpath(client->working_directory, pwd));
    return res;
}