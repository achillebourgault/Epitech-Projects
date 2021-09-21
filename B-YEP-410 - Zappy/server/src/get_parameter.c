/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/server.h"

void check_parameters(char *av, parser_t *parser, char *res)
{
    if (strcmp(av, "-p") == TRUE)
        parser->port = atoi(res);
    if (strcmp(av, "-x") == TRUE)
        parser->width = atoi(res);
    if (strcmp(av, "-y") == TRUE)
        parser->height = atoi(res);
    if (strcmp(av, "-c") == TRUE)
        parser->clientsNb = atoi(res);
    if (strcmp(av, "-f") == TRUE)
        parser->freq = atoi(res);
}

int get_parameter(parser_t *parser, char **av, char *flag, int i)
{
    char *res = NULL;
    int ret = 0;

    if (strstr(av[i], flag) && av[i + 1] != NULL && av[i + 1][0] != '-') {
        res = strdup(av[i + 1]);
        check_parameters(av[i], parser, res);
        if (strcmp(av[i], "-n") == TRUE) {
            parser->team_names = get_teams_names(av, i);
            for (ret = 0; av[ret + i] != NULL && is_flag(av[ret + i]) !=
            TRUE; ret++);
        }
    }
    return ret;
}