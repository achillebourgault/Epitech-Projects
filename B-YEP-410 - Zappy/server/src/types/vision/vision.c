/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../../include/server.h"
#include "vision.h"

int **get_pos_array(server_t *server, player_t *p)
{
    int **pos;

    if (p->vision->direction == EAST || p->vision->direction == WEST)
        pos = get_pos_array_x(server, p);
    else
        pos = get_pos_array_ns(server, p);
    return pos;
}

int count_alloc(int **pos, server_t *server)
{
    int alloc = 7;
    tile_t *tmp_tile;

    for (int y = 0; pos[y] != NULL; y++) {
        pos[y][X] = pos[y][X] < 0 ? pos[y][X] + server->world->dimensions[X]
        : pos[y][X];
        pos[y][Y] = pos[y][Y] < 0 ? pos[y][Y] + server->world->dimensions[Y]
        : pos[y][Y];
        printf("Alloc pos = x: %d y: %d\n", pos[y][X], pos[y][Y]);
        tmp_tile =
            get_tile_by_pos((int[2]) {pos[y][X], pos[y][Y]}, server->world);
        alloc += strlen(get_content_on_tile(tmp_tile)) + 3;
    }
    return alloc;
}

char *look_func(server_t *server, player_t *p)
{
    tile_t *tmp_tile;
    int **pos = get_pos_array(server, p);
    char *look;
    int alloc = count_alloc(pos, server);

    look = safe_malloc(sizeof(char) * (alloc + 1));
    look[0] = '\0';
    strcat(look, "[");
    for (int y = 0; pos[y] != NULL; y++) {
        pos[y][X] = pos[y][X] < 0 ? pos[y][X] + server->world->dimensions[X]
        : pos[y][X];
        pos[y][Y] = pos[y][Y] < 0 ? pos[y][Y] + server->world->dimensions[Y]
        : pos[y][Y];
        tmp_tile =
            get_tile_by_pos((int[2]) {pos[y][X], pos[y][Y]}, server->world);
        strcat(look, get_content_on_tile(tmp_tile));
        if (pos[y + 1] != NULL)
            strcat(look, ",");
    }
    strcat(look, "]");
    return look;
}

vision_t *init_vision(int direction, server_t *server, player_t *player)
{
    vision_t *res = safe_malloc(sizeof(vision_t));

    if (!res)
        exit(error("Malloc error."));
    res->force = 1;
    res->direction = direction;
    return res;
}
