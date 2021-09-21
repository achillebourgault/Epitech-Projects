/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "vision.h"

tile_t ***generate_map(world_t *world)
{
    tile_t ***res = safe_malloc(sizeof(tile_t **) * (world->dimensions[Y] + 1));
    int height = 0;

    for (int x = 0; height < world->dimensions[Y]; height++) {
        res[height] = (tile_t **) safe_malloc(
        sizeof(tile_t *) * (world->dimensions[X] + 1));
        for (x = 0; x < world->dimensions[X]; x++) {
        res[height][x] = init_tile((int[2]){x, height});
        }
        res[height][x] = NULL;
    }
    res[height] = NULL;
    return res;
}

world_t *generate_world(const int dimensions[2])
{
    world_t *res = safe_malloc(sizeof(world_t));

    res->dimensions[Y] = dimensions[Y];
    res->dimensions[X] = dimensions[X];
    res->map = generate_map(res);
    return res;
}