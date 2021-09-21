/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/world.h"
#include "../../include/server.h"

char *get_item_name_by_type(int type)
{
    char *ressources[8] = {"food", "linemate", "deraumere",
    "sibur", "mendiane", "phiras", "thystame", NULL};
    char *res;

    res = strdup(ressources[type]);
    return res;
}
