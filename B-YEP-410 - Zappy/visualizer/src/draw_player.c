/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include "visualizer.h"

void print_food(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->food_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->food_r, sfRed);
    sfCircleShape_setPosition(gui->tiles[y][x]->food_r, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->food_r,
    NULL);
}

void print_thystame(gui_t *gui, int y, int x)
{
    sfCircleShape_setRadius(gui->tiles[y][x]->thystame_r, 1);
    sfCircleShape_setFillColor(gui->tiles[y][x]->thystame_r, sfGreen);
    sfCircleShape_setPosition(gui->tiles[y][x]->thystame_r, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 6) * 3) - 1.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    ((sfRectangleShape_getSize(gui->tiles[y][x]->tile).y / 6) * 5) - 1.5});
    sfRenderWindow_drawCircleShape(gui->window, gui->tiles[y][x]->thystame_r,
    NULL);
}

void draw_resources(gui_t *gui, int y, int x)
{
    if (gui->tiles[y][x]->food >= 1)
        print_food(gui, y, x);
    if (gui->tiles[y][x]->linemate >= 1)
        print_linemate(gui, y, x);
    if (gui->tiles[y][x]->deraumere >= 1)
        print_deraumere(gui, y, x);
    if (gui->tiles[y][x]->sibur >= 1)
        print_sibur(gui, y, x);
    if (gui->tiles[y][x]->mendiane >= 1)
        print_mendiane(gui, y, x);
    if (gui->tiles[y][x]->phiras >= 1)
        print_phiras(gui, y, x);
    if (gui->tiles[y][x]->thystame >= 1)
        print_thystame(gui, y, x);
}

void set_player(gui_t *gui, sfColor color, int y, int x)
{
    sfCircleShape_setFillColor(gui->tiles[y][x]->circle, color);
    sfCircleShape_setPosition(gui->tiles[y][x]->circle, (sfVector2f)
    {sfRectangleShape_getPosition(gui->tiles[y][x]->tile).x +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 2) -
    (sfCircleShape_getRadius(gui->tiles[y][x]->circle)) - 0.5,
    sfRectangleShape_getPosition(gui->tiles[y][x]->tile).y +
    (sfRectangleShape_getSize(gui->tiles[y][x]->tile).x / 2) -
    (sfCircleShape_getRadius(gui->tiles[y][x]->circle)) + 0.5});
    sfCircleShape_setPointCount(gui->tiles[y][x]->circle, 3);
}

void draw_player(gui_t *gui)
{
    player_t **p_on_tile;
    sfColor color;

    for (int y = 0, x = 0; gui->tiles[y] != NULL; y++) {
        for (x = 0; gui->tiles[y][x] != NULL; x++) {
            p_on_tile = get_player_on_tile(gui, gui->tiles[y][x]);
            color = p_on_tile != NULL && p_on_tile[0] != NULL ?
            p_on_tile[0]->team_color : sfWhite;
            if (p_on_tile != NULL && p_on_tile[0] != NULL) {
                sfCircleShape_setRadius(gui->tiles[y][x]->circle,
                (float)(p_on_tile[0]->level) / 1.5);
                set_player(gui, color, y, x);
            }
            draw_resources(gui, y, x);
        }
    }
}