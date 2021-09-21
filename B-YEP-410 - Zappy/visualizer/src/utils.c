/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/visualizer.h"

void *safe_malloc(unsigned long size)
{
    void *res = malloc(size);

    if (!res)
        exit(84);
    return res;
}

int error(const char *message)
{
    printf("Error: %s\n", message);
    return ERROR;
}

int is_flag(char *arg)
{
    char *flags[7] = {"-p", "-x", "-y", "-n", "-c", "-f", NULL};
    int res = ERROR;

    for (int i = 0; flags[i] != NULL; i++) {
        if (strcmp(flags[i], arg) == TRUE) {
            res = 0;
            break;
        }
    }
    return res;
}

int random_nbr(int min, int max)
{
    int res;
    int low;
    int high;

    if (min < max) {
        low = min;
        high = max + 1;
    } else {
        low = max + 1;
        high = min;
    }
    res = (rand() % (high - low)) + low;
    return res;
}

char *clean_str(char const *str, char ban)
{
    char *res;
    int x = 0;
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ban)
            x++;
    }
    res = malloc(sizeof(char) * (strlen(str) - x + 1));
    for (x = 0; str[x] != '\0'; x++) {
        if (str[x] == ban)
            continue;
        res[cpt] = str[x];
        cpt++;
    }
    res[cpt] = '\0';
    return res;
}