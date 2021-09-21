/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/world.h"
#include "../../include/server.h"

item_t *create_item(int type)
{
    item_t *res = safe_malloc(sizeof(item_t));

    if (!res)
        exit(error("Malloc error."));
    res->type = type;
    return res;
}

int generate_stone(world_t *world, int type, double quantity)
{
    int total = quantity * world->dimensions[Y] * world->dimensions[X];
    int pos[2];

    for (int i = 0; i < total; i++) {
        pos[X] = random_nbr(0, world->dimensions[X] - 1);
        pos[Y] = random_nbr(0, world->dimensions[Y] - 1);
        add_ressource_to_tile(create_item(type), get_tile_by_pos(pos, world));
    }
    return 0;
}

int generate_food(world_t *world, int type, double quantity)
{
    int total = quantity * world->dimensions[Y] * world->dimensions[X];
    int pos[2];

    (void) type;
    for (int i = 0; i < total; i++) {
        pos[X] = random_nbr(0, world->dimensions[X] - 1);
        pos[Y] = random_nbr(0, world->dimensions[Y] - 1);
        add_ressource_to_tile(create_item(ITEM_FOOD),
        get_tile_by_pos(pos, world));
    }
    return 0;
}

void generate_ressources(world_t *world)
{
    int (*generate[7])(world_t *, int, double) = {
        generate_food, generate_stone,
        generate_stone, generate_stone, generate_stone, generate_stone,
        generate_stone
    };
    int (stones[7]) = {
        ITEM_FOOD, ITEM_LINEMATE, ITEM_DERAUMERE, ITEM_SIBUR,
        ITEM_MENDIANE, ITEM_PHIRAS, ITEM_THYSTAME
    };
    double quantity[7] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};

    for (int i = 0; i < 7; i++)
        generate[i](world, stones[i], quantity[i]);

    for (int y = 0; y < world->dimensions[Y]; y++) {
        for (int x = 0; x < world->dimensions[X]; x++) {
            tile_t *tile = get_tile_by_pos((int[2]) {y, x}, world);
        }
    }
}