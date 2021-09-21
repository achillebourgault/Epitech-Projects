/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "visualizer.h"
#include <stdio.h>
#include <unistd.h>

char *read_request(gui_t *gui)
{
    FILE *socket = fdopen(gui->config->socket, "r");
    char *buffer = NULL;
    size_t length = 120;

    getline(&buffer, &length, socket);
    return buffer;
}