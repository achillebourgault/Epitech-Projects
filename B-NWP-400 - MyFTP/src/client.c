/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../include/server.h"

client_t *new_client(myftp_t *ftp, int csock, int sinsize)
{
    client_t *client = malloc(sizeof(client_t));

    ftp->client_counts += 1;
    client->client_socket = csock;
    client->parent_directory = strdup(ftp->path);
    client->working_directory = strdup(client->parent_directory);
    client->connected = 0;
    client->data_socket = -1;
    client->param_passwd = NULL;
    client->param_user = NULL;
    return client;
}

void bind_client(client_t *client, struct sockaddr_in sin, myftp_t *ftp)
{
    if (bind(client->data_socket, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("bind()");
        exit(errno);
    }
    listen(client->data_socket, MAX_CLIENTS);
    FD_SET(client->data_socket, &ftp->current_socket);
}

int enable_passive_mode(char *command, client_t *client, myftp_t *ftp)
{
    int p1;
    int p2;
    struct sockaddr_in sin = {0};
    int port;

    if (strncmp(command, "PASV", 4) != 0)
        return ERROR;
    p1 = 19 + get_client_id_from_socket(ftp, client->client_socket);
    p2 = 15 + get_client_id_from_socket(ftp, client->client_socket);
    command = NULL;
    port = (p1 * 256) + p2;
    dprintf(client->client_socket,
        "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)\n", 127, 0, 0,
        1, p1, p2);
    client->data_socket = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    bind_client(client, sin, ftp);
    return 0;
}

int enable_active_mode(char *command, client_t *client, myftp_t *ftp)
{
    struct sockaddr_in sin = {0};

    if (strncmp(command, "PORT ", 4) != 0)
        return 84;
    command = strtok(command, "PORT ");
    command = strtok(command, "\n\r");

    client->data_socket = socket(AF_INET, SOCK_STREAM, 0);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(command));
    if (bind(client->data_socket, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
        perror("bind()");
        exit(errno);
    }
    listen(client->data_socket, MAX_CLIENTS);
    FD_SET(client->data_socket, &ftp->current_socket);
    return 0;
}

int is_connected(client_t *client, int msg)
{
    int res = 1;

    if (client->param_user != NULL && client->param_passwd != NULL)
        res = 0;
    else {
        if (msg == 1) {
            dprintf(client->client_socket, "%d Please login with USER and PASS.\n",
                530);
        }
    }
    return res;
}

