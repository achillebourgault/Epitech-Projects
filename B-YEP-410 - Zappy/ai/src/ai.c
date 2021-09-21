/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"

int can_incantation(int required[6], int tmp_inv[7])
{
    int res = 0;

    for (int i = 0; i < 6; i++) {
        if (tmp_inv[i] != required[i]) {
            res = 1;
            break;
        }
    }
    return res;
}

void run_ai(client_t *client, char *request)
{
    int required[7][6] = {{1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0},
        {2, 0, 1, 0, 2, 0}, {1, 1, 2, 0, 1, 0}, {1, 2, 1, 3, 0, 0},
        {1, 2, 3, 0, 1, 0}, {2, 2, 2, 2, 2, 1}};
    char *dir[5] = {"Forward\n", "Forward\n", "Forward\n", "Right\n", "Left\n"};
    char *new_dir;

    if (can_incantation(required[client->level - 1], client->tmp_inv) == 0)
        printf("Client can elevate\n");
    else {
        if (client->dir_has_changed == 0) {
            dprintf(client->socket, "Forward\n");
            client->dir_has_changed = 1;
        } else {
            new_dir = dir[(rand() % ((4 - 0) - 0 + 1)) + 0];
            if (strncmp(new_dir, "Forward\n", 8) != 0)
                client->dir_has_changed = 0;
            dprintf(client->socket, "%s\n", new_dir);
        }
    }
    dprintf(client->socket, "Look\n");
}

char  **handle_look(client_t *client, char *request, int required[7][6])
{
    char **tmp = NULL;
    int i = 0;

    if (strncmp(request, "[player", 7) == 0) {
        tmp = str_to_word_array(request, ",");
        tmp = str_to_word_array(tmp[0], " ");

        for ( i = 0; tmp[i] != NULL; i++) {
            if (strcmp(tmp[i], "player") != 0) {
                client->pickup = 0;
                break;
            }
        }
        if (tmp[1] != NULL) {
            sleep(1);
            dprintf(client->socket, "Take %s\n", tmp[1]);
        }
        if (can_incantation(required[client->level - 1], client->tmp_inv) == 0)
            printf("Client can elevate\n");
    }
    return tmp;
}

void handle_action(client_t *client, char *request)
{
    char **tmp = NULL;
    int required[7][6] = {{1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0},
        {2, 0, 1, 0, 2, 0}, {1, 1, 2, 0, 1, 0}, {1, 2, 1, 3, 0, 0},
        {1, 2, 3, 0, 1, 0}, {2, 2, 2, 2, 2, 1}};

    tmp = handle_look(client, request, required);
    if (tmp != NULL) {
        for (int i = 0; tmp[i] != NULL; i++)
            free(tmp[i]);
        free(tmp);
    }
}