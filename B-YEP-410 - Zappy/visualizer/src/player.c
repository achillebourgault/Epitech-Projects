/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "visualizer.h"

player_t *init_player(char *team_name, int pos[2], int color[3])
{
    player_t *res = safe_malloc(sizeof(player_t));

    res->pos[X] = pos[X];
    res->pos[Y] = pos[Y];
    res->team_name = strdup(team_name);
    res->team_color = sfColor_fromRGBA(color[0], color[1], color[2], 255);
    return res;
}

player_t **get_player_on_tile(gui_t *gui, tile_t *tile)
{
    player_t **res;
    int x = tile->pos[X];
    int y = tile->pos[Y];
    int alloc = 0;

    if (gui == NULL || gui->players == NULL)
        return NULL;
    for (int i = 0; gui->players[i] != NULL; i++) {
        if (gui->players[i]->pos[X] == x && gui->players[i]->pos[Y] == y)
            alloc++;
    }
    res = safe_malloc(sizeof(player_t *) * (alloc + 1));
    for (int i = 0, alloc = 0; gui->players[i] != NULL; i++) {
        if (gui->players[i]->pos[X] == x && gui->players[i]->pos[Y] == y) {
            res[alloc] = gui->players[i];
            alloc++;
        }
    }
    res[alloc] = NULL;
    return res;
}

void free_array(void **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
}

player_t **make_players_array(char *const *array)
{
    player_t **res = NULL;
    char **player_info = NULL;
    int current_player = 0;

    res = safe_malloc(sizeof(player_t *) * (atoi(array[1]) + 1));
    for (int k = 2; array[k] != NULL; k++) {
        player_info = str_to_word_array(array[k], "<sp>");
        if (player_info[0] && player_info[0][0] == '\n')
            break;
        res[current_player] = init_player(player_info[3],
            (int[2]) {atoi(player_info[0]), atoi(player_info[1])},
            (int[3]) {atoi(player_info[4]), atoi(player_info[5]),
                atoi(player_info[6])});
        current_player++;
    }
    res[current_player] = NULL;
    return res;
}

player_t **get_all_players(gui_t *gui)
{
    char *reply = NULL;
    char **array = NULL;

    dprintf(gui->config->socket, "vzr_plrs\n");
    reply = read_request(gui);
    reply[strlen(reply)] = '\0';
    array = str_to_word_array(strdup(reply), "<SP>");
    if (strcmp("0", array[1]) == 0) {
        free(reply);
        return NULL;
    }
    free(reply);
    return make_players_array(array);
}