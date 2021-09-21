/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "visualizer.h"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int connect_client_to_server(gui_t *gui)
{
    struct sockaddr_in server_interface;
    size_t int_size = sizeof(server_interface);

    gui->config->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (gui->config->socket == -1) {
        perror("socket()");
        return ERROR;
    }
    server_interface.sin_family = AF_INET;
    server_interface.sin_addr.s_addr = inet_addr(gui->config->machine_name);
    server_interface.sin_port = htons(gui->config->port);
    if (connect(gui->config->socket, (struct sockaddr *) &server_interface,
        int_size) != 0) {
        printf("ip: %s\n", gui->config->machine_name);
        perror("connect()");
        return ERROR;
    }
    FD_ZERO(&gui->config->current_sockets);
    FD_SET(gui->config->socket, &gui->config->current_sockets);
    return SUCCESS;
}