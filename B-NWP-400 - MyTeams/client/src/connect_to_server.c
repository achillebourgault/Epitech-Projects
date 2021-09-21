/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int connect_to_server(client_t *client)
{
    struct sockaddr_in server_interface;
    size_t int_size = sizeof(server_interface);

    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket == -1) {
        printf("socket() error\n");
        return ERROR;
    }
    server_interface.sin_family = AF_INET;
    server_interface.sin_addr.s_addr = inet_addr(client->server_ip);
    server_interface.sin_port = htons(client->server_port);
    if (connect(client->socket, (struct sockaddr *) &server_interface,
        int_size) != 0) {
        printf("connect() error\n");
        return ERROR;
    }
    FD_ZERO(&client->current_sockets);
    FD_SET(client->socket, &client->current_sockets);
    FD_SET(0, &client->current_sockets);
    return SUCCESS;
}