/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "client.h"
#include <stdio.h>
#include <fcntl.h>

char *read_request(int socket)
{
    FILE *socket_file = fdopen(socket, "r");
    char *buffer = NULL;
    size_t length = 120;

    getline(&buffer, &length, socket_file);
    return buffer;
}