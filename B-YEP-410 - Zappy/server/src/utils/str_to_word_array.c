/*
** EPITECH PROJECT, 2024
** server
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdlib.h>

char **str_to_word_array(char *str, char *sep)
{
    int alloc;
    char *count = strdup(str);
    char **res;

    if (!strtok(count, sep))
        return NULL;
    for (alloc = 1; strtok(NULL, sep) != NULL; alloc++);
    res = malloc(sizeof(char *) * (alloc + 1));
    count = strdup(str);
    res[0] = strdup(strtok(count, sep));
    for (int x = 1; x < alloc; x++)
        res[x] = strdup(strtok(NULL, sep));
    res[alloc] = NULL;
    return res;
}