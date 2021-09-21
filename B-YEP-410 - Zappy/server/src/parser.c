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

char **get_teams_names(char **av, int i)
{
    char **res = NULL;
    int size;

    i++;
    for (size = 0; av[size + i] != NULL && is_flag(av[size + i]) != 0; size++);
    res = safe_malloc(sizeof(char *) * (size + 1));
    for (size = 0; av[size + i] != NULL && is_flag(av[size + i]) != 0; size++) {
        res[size] = strdup(av[size + i]);
    }
    res[size] = NULL;
    return res;
}

parser_t *parse_server(int ac, char **av)
{
    parser_t *res = NULL;

    if (ac > 1) {
        if (strcmp(av[1], "-h") == TRUE || strcmp(av[1], "-help") == TRUE)
            exit(help());
        res = parser(av++);
        if (check_arguments(res) == ERROR)
            exit(error("All fields must be defined."));
    } else
        exit(error("Bad usage."));
    srand(time(NULL));
    return res;
}

void init(parser_t *res)
{
    res->height = -1;
    res->freq = -1;
    res->clientsNb = -1;
    res->team_names = NULL;
    res->width = -1;
    res->port = -1;
}

parser_t *parser(char **av)
{
    parser_t *res = safe_malloc(sizeof(parser_t));
    char *flags[7] = {"-p", "-x", "-y", "-n", "-c", "-f", NULL};
    int ret;

    init(res);
    for (int i = 0; av[i] != NULL; i++)
        for (int f = 0; flags[f] != NULL; f++) {
            ret = get_parameter(res, av, flags[f], i);
            i += ret;
        }
    return res;
}