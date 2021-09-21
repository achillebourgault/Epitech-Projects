/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_YEP_410_LIL_4_1_ZAPPY_ACHILLE_BOURGAULT_VISION_H
#define B_YEP_410_LIL_4_1_ZAPPY_ACHILLE_BOURGAULT_VISION_H

#define V_PLAYER 0;
#define V_FOOD 1;
#define V_LINEMATE 2;
#define V_DERAUMERE 3;
#define V_SIBUR 4;
#define V_MENDIANE 5;
#define V_PHIRAS 6;
#define V_THYSTAME 7;

typedef struct vision_s {
    int force;
    int direction;
    int ***map;
} vision_t;


#endif