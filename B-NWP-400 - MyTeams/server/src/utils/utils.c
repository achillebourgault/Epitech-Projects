/*
** EPITECH PROJECT, 2024
** dev_save
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "../../include/types.h"

int get_total_files(char *path)
{
    int size = 0;
    DIR *d;
    struct dirent *dir;

    if ((d = opendir(path))) {
        for (; (dir = readdir(d)) != NULL; size++);
        closedir(d);
    }
    return size;
}

char **get_all_files(char *path)
{
    DIR *d = opendir(path);
    struct dirent *dir;
    char **res = NULL;
    int size = get_total_files(path);

    if (size == 0 || !d)
        return res;
    res = malloc(sizeof(char *) * (size + 1));
    for (size = 0; (dir = readdir(d)) != NULL; size++) {
        res[size] = strdup(dir->d_name);
        if (strcmp(".", dir->d_name) == 0 || strcmp("..", dir->d_name) == 0)
            size--;
    }
    res[size] = NULL;
    closedir(d);
    return res;
}

user_t *get_user_by_uuid(char *uuid, user_t **users)
{
    if (users == NULL)
        return (NULL);
    for (int i = 0; users[i] != NULL; i++)
        if (strcmp(users[i]->uuid, uuid) == 0)
            return (users[i]);
    return (NULL);
}