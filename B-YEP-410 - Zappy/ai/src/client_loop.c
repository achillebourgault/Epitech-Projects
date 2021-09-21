/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"
#include <unistd.h>

char *receive_request(client_t *client)
{
    char *received_request;

    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, &client->ready_sockets)) {
            if (i == client->socket) {
                received_request = read_request(client->socket);
                return received_request;
            }
        }
    }
    return NULL;
}

void client_loop(client_t *client)
{
    int select_val = 0;
    struct timeval *tv = safe_malloc(sizeof(struct timeval));
    char *request;
    char **tmp;

    tv->tv_sec = 1;
    tv->tv_usec = 0;
    while (client->exit != 1) {
        client->ready_sockets = client->current_sockets;
        select_val = select(FD_SETSIZE, &client->ready_sockets, NULL, NULL, tv);
        if (select_val < 0) {
            printf("select() error\n");
            return;
        }
        if (select_val > 0) {
            request = receive_request(client);
            handle_action(client, request);
        }
        if (select_val == 0)
            run_ai(client, request);
    }
}