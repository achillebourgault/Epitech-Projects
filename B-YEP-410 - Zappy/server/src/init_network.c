/*
** EPITECH PROJECT, 2024
** server
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include <stdio.h>
#include "../include/server.h"

int create_socket(void)
{
    int tmp_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (tmp_socket == -1)
        perror("socket()");
    return tmp_socket;
}

struct sockaddr_in create_interface(int port, int socket)
{
    struct sockaddr_in interface = {0};
    size_t interface_size;

    interface.sin_addr.s_addr = htonl(INADDR_ANY);
    interface.sin_family = AF_INET;
    interface.sin_port = htons(port);
    interface_size = sizeof(interface);
    if (bind(socket, (struct sockaddr *) &interface, interface_size) < 0)
        perror("bind()");
    return interface;
}

int init_network(server_t *server)
{
    struct sockaddr_in interface;

    server->socket = create_socket();
    interface = create_interface(server->port, server->socket);
    if (listen(server->socket, MAX_CLIENTS) == -1 || server->socket == -1) {
        perror("listen()");
        return ERROR;
    }
    FD_ZERO(&server->current_sockets);
    FD_SET(server->socket, &server->current_sockets);
    return SUCCESS;
}

char *read_request(int socket)
{
    FILE *file = fdopen(socket, "r");
    char *buffer = NULL;
    size_t length = 64;

    getline(&buffer, &length, file);
    return buffer;
}