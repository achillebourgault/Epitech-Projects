/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include "../include/server.h"

int get_nb_char(const char *str, char c)
{
    int res = 0;

    if (!str)
        return res;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            res++;
    }
    return res;
}

int get_new_id(myftp_t *ftp)
{
    int res = -1;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (i < ftp->client_counts || ftp->current_clients[i] == NULL) {
            res = i;
            break;
        }
    }
    return res;
}

char *clean_str(const char *str, char c)
{
    char *res = malloc(sizeof(char) * (strlen(str) - get_nb_char(str, c) + 1));
    int cpt = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            continue;
        else {
            res[cpt++] = str[i];
        }
    }
    res[cpt] = '\0';
    return res;
}