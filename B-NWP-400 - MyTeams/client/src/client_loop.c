/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>

extern int exit_client;

int command_error_handling(char **command_array)
{
    int i = 1;
    size_t arg_len;

    if (command_array[0][0] != '/')
        return ERROR;
    while (command_array[i] != NULL) {
        if (command_array[i][0] != '"')
            return ERROR;
        arg_len = strlen(command_array[i]);
        if (command_array[i][arg_len - 1] != '"')
            return ERROR;
        i++;
    }
    return SUCCESS;
}

char * do_select(client_t *client)
{
    char *command = NULL;
    char **request;

    client->ready_sockets = client->current_sockets;
    if (select(FD_SETSIZE, &client->ready_sockets, NULL, NULL, NULL) < 0) {
        printf("select() error\n");
        return NULL;
    }
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, &client->ready_sockets)) {
            if (i == client->socket) {
                request = get_request(client);
                handle_request(client, request);
            }
            if (i == 0) {
                command = read_command();
            }
        }
    }
    return command;
}

void process_user_command(client_t *client, char *command)
{
    char **command_array;

    command_array = command_splitter(command);
    if (command_error_handling(command_array) == ERROR) {
        printf("Invalid command\n");
    } else {
        handle_command(client, command_array);
    }
}

void handler(int signal)
{
    exit_client = 1;
}

int client_loop(client_t *client)
{
    char *command;
    char **arglist;
    char **reply;

    signal(SIGINT, handler);
    while (exit_client != 1) {
        command = do_select(client);
        if (command != NULL) {
            process_user_command(client, command);
        }
    }
    if (client->connected == 1) {
        arglist = create_logout_arglist(client->user_uid);
        send_request(client, "150", arglist);
        reply = get_request(client);
        handle_logout_request(client, reply);
    }
}