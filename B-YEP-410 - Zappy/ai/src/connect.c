/*
** EPITECH PROJECT, 2024
** dummy_server
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include "client.h"

int connect_client_to_server(client_t *client)
{
    struct sockaddr_in server_interface;
    size_t int_size = sizeof(server_interface);

    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client->socket == -1) {
        perror("socket()");
        return ERROR;
    }
    server_interface.sin_family = AF_INET;
    server_interface.sin_addr.s_addr = inet_addr(client->server_ip);
    server_interface.sin_port = htons(client->server_port);
    if (connect(client->socket, (struct sockaddr *) &server_interface,
        int_size) != 0) {
        perror("connect()");
        return ERROR;
    }
    fcntl(client->socket, O_NONBLOCK);
    FD_ZERO(&client->current_sockets);
    FD_SET(client->socket, &client->current_sockets);
    return SUCCESS;
}