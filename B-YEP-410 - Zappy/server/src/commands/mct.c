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

char *get_tile_content(const int *count, const int *tile_to_get)
{
    char *ret = malloc(sizeof(char) * 31);

    sprintf(ret, "<SP>%d %d %d %d %d %d %d %d %d", tile_to_get[X],
        tile_to_get[Y], count[0], count[1], count[2], count[3], count[4],
        count[5], count[6]);
    return ret;
}

char **generate_mct_array(server_t *server, const int *world_size)
{
    int cpt = 0;
    tile_t *tile;
    int *count;
    char **array = malloc(sizeof(char *) * (world_size[X] * world_size[Y] + 1));

    for (int y = 0; y != world_size[Y]; y++) {
        for (int x = 0; x != world_size[X]; x++) {
            tile = get_tile_by_pos((int[2]){x, y}, server->world);
            if (tile != NULL) {
                count = get_items_in_tile(tile);
                array[cpt] = get_tile_content(count, (int[2]) {x, y});
                cpt++;
            }
        }
    }
    array[cpt] = NULL;
    return array;
}

char *make_mct_reply(server_t *server, const int *world_size)
{
    size_t total_size = 0;
    char **array = generate_mct_array(server, world_size);
    char *res;

    for (int i = 0; array[i] != NULL; i++)
        total_size += strlen(array[i]);
    res = malloc(sizeof(char) * total_size + 4);
    sprintf(res, "mct");
    for (int i = 0; array[i] != NULL; i++)
        strcat(res, array[i]);
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
    return res;
}

int cmd_mct(server_t *server, char **command, int socket)
{
    int world_size[2];
    char *reply;

    if (strncmp("mct", command[0], 3) != 0) {
        return ERROR;
    }
    world_size[X] = server->world->dimensions[X];
    world_size[Y] = server->world->dimensions[Y];
    reply = make_mct_reply(server, world_size);
    dprintf(socket, "%s\n", reply);
    free(reply);
    return SUCCESS;
}