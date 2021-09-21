/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdlib.h>
#include <string.h>
#include "../../../include/server.h"

int get_array_size_ns(server_t *server, player_t *p)
{
    int tmp_level = 0;
    int cpt = 0;

    for (int y = p->pos[Y], x = 0;
        y > p->pos[Y] - (p->level + 1) && tmp_level <= p->level; y--) {
        for (x = p->pos[X] - (tmp_level); x < p->pos[X] +
        (tmp_level + 1); x++) {
            cpt++;
        }
        tmp_level++;
    }
    return cpt + 1;
}

int **get_pos_array_ns(server_t *server, player_t *p)
{
    int cpt = 0;
    int tmp_level = 0;
    int size = get_array_size_ns(server, p);
    int **pos = malloc(sizeof(int **) * (size + 1));

    for (int y = p->pos[Y], x = 0;
        y > p->pos[Y] - (p->level + 1) && tmp_level <= p->level;) {
        pos[cpt] = malloc(sizeof(int *) * 2);
        for (x = p->pos[X] - (tmp_level);
        x < p->pos[X] + (tmp_level + 1); x++) {
            pos[cpt] = malloc(sizeof(int *) * 2);
            pos[cpt][0] = server->world->dimensions[X] == x ? x - 1 : x;
            pos[cpt][1] = server->world->dimensions[Y] == y ? y - 1 : y;
            cpt++;
        }
        tmp_level++;
        p->vision->direction == NORTH ? y-- : y++;
    }
    pos[cpt] = NULL;
    return pos;
}

int get_array_size_x(server_t *server, player_t *p)
{
    int tmp_level = 0;
    int cpt = 0;

    for (int x = p->pos[X], y = 0;
        x > p->pos[X] - (p->level + 1) && tmp_level <= p->level; x--) {
        for (y = p->pos[Y] - (tmp_level); y < p->pos[Y] +
        (tmp_level + 1); y++) {
            cpt++;
        }
        tmp_level++;
    }
    return cpt + 1;
}

int **get_pos_array_x(server_t *server, player_t *p)
{
    int cpt = 0;
    int tmp_level = 0;
    int size = get_array_size_x(server, p);
    int **pos = malloc(sizeof(int **) * (size + 1));

    for (int x = p->pos[X], y = 0;
        x > p->pos[X] - (p->level + 1) && tmp_level <= p->level;) {
        pos[cpt] = malloc(sizeof(int *) * 2);
        for (y = p->pos[Y] - (tmp_level); y < p->pos[Y] +
        (tmp_level + 1); y++) {
            pos[cpt] = malloc(sizeof(int *) * 2);
            pos[cpt][0] = server->world->dimensions[X] == x ? x - 1 : x;
            pos[cpt][1] = server->world->dimensions[Y] == y ? y - 1 : y;
            cpt++;
        }
        tmp_level++;
        p->vision->direction == WEST ? x-- : x++;
    }
    pos[cpt] = NULL;
    return pos;
}