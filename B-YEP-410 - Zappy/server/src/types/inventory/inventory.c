/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../../../include/types/player.h"
#include "../../../include/world.h"
#include "../../../include/server.h"

inventory_t *init_inventory(void)
{
    inventory_t *res = safe_malloc(sizeof(inventory_t));

    if (!res)
        exit(error("Malloc error."));
    res->food = 0;
    for (int i = 0; i < 7; i++)
        res->stones[i] = 0;
    return res;
}

int get_id_by_name(char *name)
{
    char *comp[8] = {"food", "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame", NULL};
    int id;

    printf("<%s>", name);

    for (id = 0; comp[id] != NULL; id++) {
        if (strncmp(name, comp[id], strlen(comp[id])) == 0)
            break;
    }
    if (comp[id] == NULL)
        perror("Error get_id_by_name\n");
    return id;
}

char *get_inventory_data(player_t *player)
{
    char *res = safe_malloc(sizeof(char) * (100));

    sprintf(res,
        "[food %d, sibur %d, phiras %d, linemate %d, mendiane %d,"
        "thystame %d, deraumere %d]\n",
        player->inventory->food, player->inventory->stones[ITEM_SIBUR],
        player->inventory->stones[ITEM_PHIRAS],
        player->inventory->stones[ITEM_LINEMATE],
        player->inventory->stones[ITEM_MENDIANE],
        player->inventory->stones[ITEM_THYSTAME],
        player->inventory->stones[ITEM_DERAUMERE]);
    return res;
}

void add_item_to_inventory(player_t *player, int item, int quantity)
{
    if (item == ITEM_FOOD)
        player->inventory->food += quantity;
    else
        player->inventory->stones[item] += quantity;
}

void use_item(player_t *player, int item, int quantity)
{
    if (item == ITEM_FOOD) {
        player->time_units += CONFIG_FOOD_FEED_UNITS;
        player->inventory->food -= quantity;
    } else
        player->inventory->stones[item] -= quantity;
}