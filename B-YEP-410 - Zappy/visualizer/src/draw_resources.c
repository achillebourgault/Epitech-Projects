/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include "visualizer.h"

void print_linemate(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->linemate_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->linemate_r, sfYellow);
    sfCircleShape_setPosition(gui->tiles[y][x]->linemate_r, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) * 3) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->linemate_r,
    NULL);
}

void print_deraumere(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->deraumere_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->deraumere_r, sfBlack);
    sfCircleShape_setPosition(gui->tiles[y][x]->deraumere_r,
    (sfVector2f) {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) * 5) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->deraumere_r,
    NULL);
}

void print_sibur(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->sibur_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->sibur_r, sfBlue);
    sfCircleShape_setPosition(gui->tiles[y][x]->sibur_r, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) * 3) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->sibur_r,
    NULL);
}

void print_mendiane(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->mendiane_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->mendiane_r, sfCyan);
    sfCircleShape_setPosition(gui->tiles[y][x]->mendiane_r, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) * 5) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) * 3) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->mendiane_r,
    NULL);
}

void print_phiras(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->phiras_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->phiras_r, sfMagenta);
    sfCircleShape_setPosition(gui->tiles[y][x]->phiras_r, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) * 5) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->phiras_r,
    NULL);
}