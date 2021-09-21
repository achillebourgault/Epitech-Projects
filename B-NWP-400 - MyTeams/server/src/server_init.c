/*
** EPITECH PROJECT, 2021
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/my_teams.h"

int create_socket(void)
{
    int tmpsocket = socket(AF_INET, SOCK_STREAM, 0);
    if (tmpsocket == -1) {
        printf("socket() error\n");
    }
    return tmpsocket;
}

int create_server_interface(my_teams_t *teams)
{
    struct sockaddr_in tmpinterface = {0};
    size_t intsize;
    tmpinterface.sin_addr.s_addr = htonl(INADDR_ANY);
    tmpinterface.sin_family = AF_INET;
    tmpinterface.sin_port = htons(teams->server->port);
    intsize = sizeof(tmpinterface);
    if (bind(teams->server->socket, (struct sockaddr *)&tmpinterface, intsize) <
        0) {
        printf("Port is already use. Please use another.");
        return ERROR;
    }
    return 0;
}

int listen_socket(int socket)
{
    if (listen(socket, MAX_CLIENTS) == -1) {
        printf("listen() error.");
        return ERROR;
    }
    return 0;
}

void init_teams_server(my_teams_t *teams)
{
    teams->server->socket = create_socket();
    create_server_interface(teams);
    listen_socket(teams->server->socket);
    FD_ZERO(&teams->server->current_sockets);
    FD_SET(teams->server->socket, &teams->server->current_sockets);
    teams->server->cli_socket = malloc(sizeof(int *) * MAX_CLIENTS);
    teams->server->cli_socket[0] = -42;
    init_data();
    load_data_beginning(teams);
}