/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "visualizer.h"

void init_visualizer(gui_t *gui)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2u winsize;
    const sfView *view;

    gui->window =
        sfRenderWindow_create(mode, "Zappy GUI", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(gui->window, 60);
    winsize = sfRenderWindow_getSize(gui->window);
    view = sfRenderWindow_getDefaultView(gui->window);
    if (!gui->window)
        exit(1);
    gui->players = NULL;
    gui->ressources = NULL;
    gui->camera_pos[Y] = winsize.y / 2;
    gui->camera_pos[X] = winsize.x / 2;
    gui->zoom = 1;
    gui->tiles =
        safe_malloc(sizeof(sfRectangleShape **) * (gui->map_size[Y] + 2));
    init_tiles(gui);
    sfRenderWindow_setView(gui->window, view);
}

void moov_cam(gui_t *gui, sfEvent event, int distance)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        gui->camera_pos[Y] -= distance;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        gui->camera_pos[X] -= distance;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        gui->camera_pos[Y] += distance;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        gui->camera_pos[X] += distance;
}

void catch_camera_movement(gui_t *gui, sfEvent event)
{
    sfView *view = sfView_copy(sfRenderWindow_getDefaultView(gui->window));
    int distance = 10;

    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyQ) ||
        sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyD) ||
        event.type == sfEvtMouseWheelMoved) {
        moov_cam(gui, event, distance);
        if (event.type == sfEvtMouseWheelMoved) {
            if (event.mouseWheel.delta == -1)
                gui->zoom += 1;
            else if (gui->zoom != 0)
                gui->zoom -= 1;
            sfView_zoom(view, (float)gui->zoom / 100);

        }
        sfView_setCenter(view,
            (sfVector2f) {gui->camera_pos[X], gui->camera_pos[Y]});
        sfRenderWindow_setView(gui->window, view);
    }
}

void gameloop(gui_t *gui)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(gui->window)) {
        update_data(gui);
        while (sfRenderWindow_pollEvent(gui->window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(gui->window);
            if (event.type == sfEvtKeyPressed ||
            event.type == sfEvtMouseWheelMoved)
                catch_camera_movement(gui, event);
        }
        sfRenderWindow_clear(gui->window, sfBlack);
        draw(gui);
        sfRenderWindow_display(gui->window);
    }
}