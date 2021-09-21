/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int exit_client;

client_t *display_help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\t");
    printf("ip\tis the server ip address on which the server socket listens");
    printf("\n\tport\tis the port number on which the server socket listens\n");
    return NULL;
}

client_t *parser(int ac, char **av)
{
    client_t *client;

    if (ac == 2) {
        if (strncmp(av[1], "-help", 5) == 0)
            return display_help();
        else {
            printf("%s: Invalid argument.\n", av[0]);
            return NULL;
        }
    } else if (ac == 3) {
        client = malloc(sizeof(client_t));
        client->server_ip = strdup(av[1]);
        client->server_port = atoi(av[2]);
        client->connected = 0;
        client->use = malloc(sizeof(*client->use) * 3);
        return client;
    } else {
        printf("%s: Invalid argument.\n", av[0]);
        return NULL;
    }
}

int error_handling(client_t *client)
{
    int count = 0;

    if (client->server_port < 0 || client->server_port > 65535) {
        printf("Invalid server port.\n");
        return ERROR;
    }
    if (client->server_ip == NULL) {
        printf("Invalid server ip.\n");
        return ERROR;
    }
    for (int i = 0; client->server_ip[i] != '\0'; i++) {
        if (client->server_ip[i] == '.')
            count++;
    }
    if (count != 3) {
        printf("Invalid server ip.\n");
        return ERROR;
    }
    return SUCCESS;
}

int main(int ac, char **av)
{
    client_t *client = parser(ac, av);

    if (client == NULL ||  error_handling(client) == ERROR)
        return ERROR;
    connect_to_server(client);
    exit_client = 0;
    client_loop(client);
    close(client->socket);
    free(client->server_ip);
    free(client);
}