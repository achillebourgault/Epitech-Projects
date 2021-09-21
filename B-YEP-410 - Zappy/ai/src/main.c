/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"

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

client_t *parse_client(parser_t *parser)
{
    client_t *res = safe_malloc(sizeof(client_t));

    if (parser->machine_name == NULL || parser->port == -1 ||
        parser->team_name == NULL) {
        perror("All Fields must be defined.");
        return NULL;
    }
    res->server_ip = strdup(parser->machine_name);
    res->server_port = parser->port;
    res->team_name = strdup(parser->team_name);
    res->exit = 0;
    res->level = 1;
    res->dir_has_changed = 1;
    res->pickup = 1;
    for (int i = 0; i < 7; i++)
        res->tmp_inv[i] = 0;
    return res;
}

int do_login(client_t *client)
{
    char *request;

    request = read_request(client->socket);
    free(request);
    dprintf(client->socket, "%s\n", client->team_name);
    request = read_request(client->socket);
    if (atoi(request) == 0) {
        printf("Cannot connect ai to server: to many players in the team\n");
        return ERROR;
    }
    free(request);
    request = read_request(client->socket);
    free(request);
    return SUCCESS;
}

int main(int ac, char **av)
{
    parser_t *parse = parse_server(ac, av);
    client_t *client = parse_client(parse);

    if (client == NULL || error_handling(client) == ERROR)
        return ERROR;
    if (connect_client_to_server(client) == ERROR) {
        free(client->server_ip);
        free(client);
        return 0;
    }
    if (do_login(client) == SUCCESS) {
        client_loop(client);
    }
    close(client->socket);
    free(client->server_ip);
    free(client);
    return 0;
}