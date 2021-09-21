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

void free_gui(gui_t *gui)
{
    sfRenderWindow_destroy(gui->window);
    free(gui->config->machine_name);
}

void open_gui(gui_t *gui)
{
    send_login_request(gui);
    init_visualizer(gui);
    gameloop(gui);
    free_gui(gui);
}