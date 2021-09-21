/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/visualizer.h"

int help(void)
{
    return 0;
}

int get_parameter(parser_t *parser, char **av, char *flag, int i)
{
    char *res = NULL;
    int ret = 0;

    if (strstr(av[i], flag) && av[i + 1] != NULL && av[i + 1][0] != '-') {
        res = strdup(av[i + 1]);
        if (strcmp(av[i], "-p") == TRUE)
            parser->port = atoi(res);
        if (strcmp(av[i], "-h") == TRUE)
            parser->machine_name = strdup(res);
    }
    return ret;
}

parser_t *parse_server(int ac, char **av)
{
    parser_t *res = NULL;

    if (ac > 1) {
        if (strcmp(av[1], "-help") == TRUE)
            exit(help());
        res = parser(av++);
    } else
        exit(error("Bad usage."));
    return res;
}

void init(parser_t *res)
{
    res->port = -1;
    res->machine_name = strdup("localhost");
}

parser_t *parser(char **av)
{
    parser_t *res = safe_malloc(sizeof(parser_t));
    char *flags[3] = {"-p", "-h", NULL};
    int ret;

    init(res);
    for (int i = 0; av[i] != NULL; i++)
        for (int f = 0; flags[f] != NULL; f++) {
            ret = get_parameter(res, av, flags[f], i);
            i += ret;
        }
    return res;
}