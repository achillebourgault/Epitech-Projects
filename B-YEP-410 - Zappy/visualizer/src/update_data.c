/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "visualizer.h"

void update_data(gui_t *gui)
{
    if (gui->ressources != NULL) {
        for (int i = 0; gui->ressources[i] != NULL; i++)
            free(gui->ressources[i]);
    }
    if (gui->players != NULL) {
        for (int i = 0; gui->players[i] != NULL; i++)
            free(gui->players[i]);
    }
    gui->ressources = get_all_ressources(gui);
    gui->players = get_all_players(gui);
}