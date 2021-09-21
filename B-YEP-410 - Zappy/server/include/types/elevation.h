/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_YEP_410_LIL_4_1_ZAPPY_ACHILLE_BOURGAULT_ELEVATION_H
#define B_YEP_410_LIL_4_1_ZAPPY_ACHILLE_BOURGAULT_ELEVATION_H

#include "player.h"
#include "../server.h"

typedef struct elevation_s {
    player_t *player;
    int new_level;
    int players_required;
    int stones_required[6];
} elevation_t;

int ask_elevation(server_t *server, player_t *player);

#endif