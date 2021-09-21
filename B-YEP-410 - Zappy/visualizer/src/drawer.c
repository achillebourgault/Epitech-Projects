/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include "visualizer.h"

sfVector2u get_winsize(gui_t *gui)
{
    sfVector2u winsize = sfRenderWindow_getSize(gui->window);

    return winsize;
}

void init_tiles(gui_t *gui)
{
    float tile_size_x = 16 + gui->map_size[X] / 3;
    float tile_size_y = 16 + gui->map_size[Y] / 3;
    float o_x = get_winsize(gui).x / 2 -
    ((gui->map_size[X] * tile_size_x) / 2);
    float o_y = get_winsize(gui).y / 2 -
    ((gui->map_size[Y] * tile_size_y) / 2);

    gui->tiles = safe_malloc(sizeof(tile_t **) * (gui->map_size[Y] + 2));
    for (int y = 0, x = 0; y < gui->map_size[Y]; y++) {
        gui->tiles[y] = safe_malloc(sizeof(tile_t *) * (gui->map_size[X] + 2));
        for (x = 0; x < gui->map_size[X]; x++) {
            gui->tiles[y][x] = init_tile(gui, (int[2]){x, y},
            (float[2]){o_x, o_y}, (float[2]){tile_size_x, tile_size_y});
            o_x += tile_size_x;
        }
        gui->tiles[y][x] = NULL;
        o_x = get_winsize(gui).x / 2- ((gui->map_size[X] * tile_size_x) / 2);
        o_y += tile_size_y;
    }
    gui->tiles[gui->map_size[Y]] = NULL;
}

player_t *get_first_player(gui_t *gui, tile_t *tile)
{
    int y = tile->pos[Y];
    int x = tile->pos[X];

    for (int i = 0; gui->players[i] != NULL; i++) {
        if (gui->players[i]->pos[X] == x && gui->players[i]->pos[Y] == Y)
            return gui->players[i];
    }
}

void draw_tiles(gui_t *gui)
{
    player_t **p_on_tile;
    sfColor color;

    for (int y = 0, x = 0; gui->tiles[y] != NULL; y++) {
        for (x = 0; gui->tiles[y][x] != NULL; x++) {
            p_on_tile = get_player_on_tile(gui, gui->tiles[y][x]);
            color = p_on_tile != NULL && p_on_tile[0] != NULL ?
            p_on_tile[0]->team_color : sfWhite;
            sfRectangleShape_setFillColor(gui->tiles[y][x]->tile, color);
            sfRenderWindow_drawRectangleShape(gui->window,
            gui->tiles[y][x]->tile, NULL);
        }
    }
}

void draw(gui_t *gui)
{
    draw_tiles(gui);
    draw_player(gui);
}