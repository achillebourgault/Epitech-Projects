/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdio.h>
#include <stdlib.h>
#include "visualizer.h"

void send_login_request(gui_t *gui)
{
    char *buffer = NULL;
    char **reply = NULL;
    int player_count;
    int team_count;

    buffer = read_request(gui);
    dprintf(gui->config->socket, "vzr_lgn\n");
    buffer = read_request(gui);
    reply = str_to_word_array(buffer, "<SP>");
    team_count = atoi(reply[2]);
    player_count = atoi(reply[3]);
    gui->players =
        safe_malloc(sizeof(player_t *) * (player_count * team_count + 1));
    reply = str_to_word_array(reply[1], " ");
    gui->map_size[X] = atoi(reply[0]);
    gui->map_size[Y] = atoi(reply[1]);
}