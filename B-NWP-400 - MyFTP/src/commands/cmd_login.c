/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdio.h>
#include "../../include/server.h"

int command_execute_user(char *command, client_t *client, myftp_t *ftp)
{
    int res = 0;

    if (strncmp(command, "USER ", 5) != 0)
        return 84;
    command = strtok(command, "USER ");
    command = strtok(command, "\n\r");
    if (strncmp(command, "Anonymous", 9) == 0 ||
        strncmp(command, "anonymous", 9) == 0) {
        client->param_user = strdup("Anonymous");
        if (client->param_passwd != NULL)
            dprintf(client->client_socket, "%d Login successful.\n", 230);
        else
            dprintf(client->client_socket,
                "%d User name okay, need password.\n", 331);
    } else {
        dprintf(client->client_socket, "%d Login incorrect.\n", 530);
    }
    return res;
}

int command_execute_passwd(char *command, client_t *client, myftp_t *ftp)
{
    int res = 0;

    if (strncmp(command, "PASS ", 5) != 0)
        return 84;
    client->param_passwd = " ";
    if (client->param_user != NULL)
        dprintf(client->client_socket, "%d Login successful.\n", 230);
    return res;
}