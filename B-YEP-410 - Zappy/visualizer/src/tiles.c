/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "visualizer.h"

void create_resources(tile_t *res)
{
    res->food_r = sfCircleShape_create();
    res->linemate_r = sfCircleShape_create();
    res->deraumere_r = sfCircleShape_create();
    res->sibur_r = sfCircleShape_create();
    res->mendiane_r = sfCircleShape_create();
    res->phiras_r = sfCircleShape_create();
    res->thystame_r = sfCircleShape_create();
}

tile_t *init_tile(gui_t *gui, int pos[2], float pos2[2], float tile_size[2])
{
    tile_t *res = safe_malloc(sizeof(tile_t));

    res->pos[X] = pos[X];
    res->pos[Y] = pos[Y];
    res->color = sfWhite;
    res->tile = sfRectangleShape_create();
    sfRectangleShape_setPosition(res->tile, (sfVector2f) {pos2[X], pos2[Y]});
    sfRectangleShape_setSize(res->tile, (sfVector2f)
    {tile_size[X], tile_size[Y]});
    sfRectangleShape_setFillColor(res->tile, sfWhite);
    sfRectangleShape_setOutlineThickness(res->tile, 1);
    sfRectangleShape_setOutlineColor(res->tile, sfGreen);
    res->circle = sfCircleShape_create();
    sfCircleShape_setOutlineThickness(res->circle, 1.2);
    sfCircleShape_setOutlineColor(res->circle, sfWhite);
    create_resources(res);
    return res;
}