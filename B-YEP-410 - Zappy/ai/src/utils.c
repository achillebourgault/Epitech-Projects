/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

int error(const char *message)
{
    printf("Error: %s\n", message);
    return ERROR;
}

void *safe_malloc(unsigned long size)
{
    void *res = malloc(size);

    if (!res)
        exit(error("Malloc error."));
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
        if (str[x] != ban) {
            res[cpt] = str[x];
            cpt++;
        }
    }
    res[cpt] = '\0';
    return res;
}