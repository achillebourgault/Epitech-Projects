/*
** EPITECH PROJECT, 2024
** server
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "../include/server.h"

void increment_action_player(server_t *server)
{
    for (int i = 0; server->teams[i] != NULL; i++)
        for (int j = 0; server->teams[i]->players[j] != NULL; j++)
            if (server->teams[i]->players[j]->action > 0)
                server->teams[i]->players[j]->action--;
}

void request_handler(server_t *server, char *buffer, int socket)
{
    char **command;
    int (*functionptr[COMMAND_COUNT])(server_t *, char **, int) = {
        cmd_vzr_plrs, cmd_msz, cmd_bct, cmd_mct, cmd_tna, cmd_ppo,
        cmd_plv, cmd_pin, cmd_pex, cmd_pbc, cmd_pic, cmd_pie, cmd_pfk,
        cmd_pdr, cmd_pgt, cmd_pdi, cmd_enw, cmd_eht, cmd_ebo, cmd_edi,
        cmd_sgt, cmd_sst, cmd_seg, cmd_smg, cmd_suc, cmd_sbp,
        cmd_forward, cmd_right, cmd_left, cmd_look, cmd_inventory,
        cmd_broadcast_text, cmd_connect_nbr, cmd_fork, cmd_eject,
        cmd_take_object, cmd_set_object, cmd_incantation, cmd_unknown
    };

    command = str_to_word_array(buffer, " ");
    for (int i = 0; i != COMMAND_COUNT; i++) {
        if (functionptr[i](server, command, socket) == SUCCESS) {
            break;
        }
    }
}

void accept_new_connection(server_t *server)
{
    int tmp_clisock;
    struct sockaddr_in tmp_cliint = {0};
    unsigned int tmp_intsize = sizeof(struct sockaddr_in);
    char *request;

    tmp_clisock =
        accept(server->socket, (struct sockaddr *) &tmp_cliint, &tmp_intsize);
    if (tmp_clisock == -1) {
        perror("accept()");
        return;
    }
    server->sock_array[tmp_clisock] = 0;
    FD_SET(tmp_clisock, &server->current_sockets);
    dprintf(tmp_clisock, "WELCOME\n");
    request = read_request(tmp_clisock);
    if (strncmp("vzr_lgn", request, 7) == 0)
        vzr_lgn(server, tmp_clisock);
    else
        login_player(server, request, tmp_clisock);
}

void handle_connection(server_t *server, int socket)
{
    FILE *file = fdopen(socket, "r");
    char *buffer = NULL;
    size_t length = 64;

    getline(&buffer, &length, file);
    if (strlen(buffer) == 0) {
    server->sock_array[socket]++;
        if (server->sock_array[socket] > 10) {
            close(socket);
            FD_CLR(socket, &server->current_sockets);
            printf("Closed socket %d\n", socket);
        }
        return;
    }
    request_handler(server, buffer, socket);
}

void server_loop(server_t *server)
{
    struct timeval *tv = safe_malloc(sizeof(struct timeval));
    tv->tv_sec = 0; tv->tv_usec = 0;
    clock_t begin = clock(); clock_t end;

    while (server->quit != 1) {
        server->ready_sockets = server->current_sockets;
        if (select(FD_SETSIZE, &server->ready_sockets, NULL, NULL, tv) < 0) {
            perror("select()"); return;
        }
        for (int i = 0; i < FD_SETSIZE; i++)
            if (FD_ISSET(i, &server->ready_sockets))
                if (i == server->socket)
                    accept_new_connection(server);
                else
                    handle_connection(server, i);
        end = clock();
        if (end >= (begin + 1 * (CLOCKS_PER_SEC / server->config->freq))) {
            begin = end;
            increment_action_player(server);
        }
    }
}
