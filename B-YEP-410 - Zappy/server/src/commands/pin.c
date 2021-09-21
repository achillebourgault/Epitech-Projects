/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/server.h"

int cmd_pin(server_t *server, char **command, int socket)
{
    player_t *p;
    int index;

    if (strcmp("pin", command[0]) != 0 || command[1] == NULL)
        return ERROR;
    index = atoi(strtok(command[1], "#"));
    p = get_player_by_index(get_all_players(server), index);
    if (p == NULL) {
        dprintf(socket, "ko\n");
        return SUCCESS;
    }
    dprintf(socket, "pin %d %d %d %d %d %d %d %d %d %d\n",
    index, p->pos[X], p->pos[Y],
        p->inventory->food, p->inventory->stones[ITEM_LINEMATE],
        p->inventory->stones[ITEM_DERAUMERE],
        p->inventory->stones[ITEM_SIBUR],
        p->inventory->stones[ITEM_MENDIANE],
        p->inventory->stones[ITEM_PHIRAS],
        p->inventory->stones[ITEM_THYSTAME]);
    return SUCCESS;
}