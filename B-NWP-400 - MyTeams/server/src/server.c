/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my_teams.h"

int *malloc_int(my_teams_t *teams, int socket)
{
    int nb = 0;

    for (; teams->server->cli_socket[nb] != -42; nb++);
    if (nb != MAX_CLIENTS) {
        teams->server->cli_socket[nb] = socket;
        teams->server->cli_socket[nb + 1] = -42;
    }
    return (teams->server->cli_socket);
}

int accept_new_connection(my_teams_t *teams)
{
    int tmp_clisock;
    struct sockaddr_in tmp_cliint = {0};
    unsigned int tmp_intsize = sizeof(struct sockaddr_in);

    tmp_clisock = accept(teams->server->socket, (struct sockaddr *)&tmp_cliint,
        &tmp_intsize);
    if (tmp_clisock == -1) {
        perror("accept()");
        return ERROR;
    }
    FD_SET(tmp_clisock, &teams->server->current_sockets);
    teams->server->cli_socket = malloc_int(teams, tmp_clisock);
    return 1;
}

int handleconnection(my_teams_t *teams, int socket)
{
    char buffer[BUFSIZE];
    int readchar;

    readchar = read(socket, buffer, BUFSIZE);
    buffer[readchar] = '\0';
    handle_commands(teams, socket, buffer);
    return 0;
}

int start_teams_server(my_teams_t *teams)
{
    printf("start server [%d]\n", teams->server->port);
    while (42) {
        teams->server->ready_sockets = teams->server->current_sockets;
        if (select(FD_SETSIZE, &teams->server->ready_sockets, NULL, NULL,
            NULL) < 0) {
            perror("select()");
            return ERROR;
        }
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &teams->server->ready_sockets)) {
                if (i == teams->server->socket) {
                    accept_new_connection(teams);
                } else {
                    handleconnection(teams, i);
                }
            }
        }
    }
}

void close_server(my_teams_t *teams)
{
}