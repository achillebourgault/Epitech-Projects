/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int get_total_files(char *path, int include_misc)
{
    int res = -1;
    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        res = 0;
        while ((dir = readdir(d)) != NULL) {
            res++;
        }
        closedir(d);
    }
    return res;
}

char **get_files(char *path, int include_misc)
{
    char **res = get_total_files(path, include_misc) > 0 ?
        malloc(sizeof(char *) * (get_total_files(path, include_misc) + 1)) :
        NULL;
    DIR *d;
    int cpt = 0;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            res[cpt++] = strdup(dir->d_name);
        }
        res[cpt] = NULL;
        closedir(d);
    }
    return res;
}