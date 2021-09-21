/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void send_request(client_t *client, char *code, char **arg_list)
{
    char *buffer;
    size_t buf_size = 3;

    if (arg_list != NULL) {
        for (int i = 0; arg_list[i] != NULL; i++) {
            buf_size += 4;
            buf_size += strlen(arg_list[i]);
        }
    }
    buffer = malloc(sizeof(char) * (buf_size + 1));
    buffer = strcpy(buffer, code);
    if (arg_list != NULL) {
        for (int i = 0; arg_list[i] != NULL; i++) {
            buffer = strcat(buffer, "<SP>");
            buffer = strcat(buffer, arg_list[i]);
        }
    }
    dprintf(client->socket, "%s", buffer);
}