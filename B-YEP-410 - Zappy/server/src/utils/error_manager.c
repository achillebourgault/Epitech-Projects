/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <time.h>
#include <printf.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/server.h"

void debug(int socket, char *print)
{
    if (DEBUG_MODE == 0)
        return;
    if (socket == -42)
        printf("%s\n", print);
    else
        dprintf(socket, "%s\n", print);
}

void free_array(void **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
}

int check_arguments(parser_t *res)
{
    int status = ERROR;

    if (res->width != -1 && res->team_names != NULL && res->clientsNb != -1 &&
        res->freq != -1 && res->height != -1 && res->port != -1) {
        status = 0;
    }
    return status;
}