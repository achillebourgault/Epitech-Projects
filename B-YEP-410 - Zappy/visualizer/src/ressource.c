/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include "visualizer.h"

ressource_t *init_ressource(int type, int pos[2])
{
    ressource_t *res = safe_malloc(sizeof(ressource_t));

    res->pos[X] = pos[X];
    res->pos[Y] = pos[Y];
    res->type = type;
    return res;
}

void add_amount(gui_t *gui, char *array, int y, int x)
{
    gui->tiles[y][x]->food = atoi(&array[4]);
    gui->tiles[y][x]->linemate = atoi(&array[6]);
    gui->tiles[y][x]->deraumere = atoi(&array[8]);
    gui->tiles[y][x]->sibur = atoi(&array[10]);
    gui->tiles[y][x]->mendiane = atoi(&array[12]);
    gui->tiles[y][x]->phiras = atoi(&array[14]);
    gui->tiles[y][x]->thystame = atoi(&array[16]);
}

void full_struct(char **array, gui_t *gui)
{
    int i = 1;
    int j = 0;

    for (int y = 0, x = 0; gui->tiles[y] != NULL && array[i] != NULL; y++) {
        for (x = 0; gui->tiles[y][x] != NULL && array[i] != NULL; x++) {
            add_amount(gui, array[i], y, x);
            i++;
        }
    }
}

ressource_t **get_all_ressources(gui_t *gui)
{
    ressource_t **res = NULL;
    char *reply = NULL;
    char **array = NULL;

    dprintf(gui->config->socket, "mct\n");
    reply = read_request(gui);
    reply[strlen(reply)] = '\0';
    array = str_to_word_array(strdup(reply), "<SP>");
    if (array[0] != NULL)
        full_struct(array, gui);
    return res;
}

