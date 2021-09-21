/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "myteams_client.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *read_request(int socket)
{
    int readchar;
    char *buffer = malloc(sizeof(char) * (BUFSIZE + 1));

    readchar = read(socket, buffer, BUFSIZE);
    buffer[readchar] = '\0';
    return buffer;
}

char **get_request(client_t *client)
{
    char *request = read_request(client->socket);
    char **array = str_to_word_array(request, "<SP>");

    free(request);
    return array;
}