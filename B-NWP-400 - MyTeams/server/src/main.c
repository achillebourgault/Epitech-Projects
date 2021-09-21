/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_teams.h"

my_teams_t *usage(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("    port is the port number on which the server socket listens.\n");
    return NULL;
}

my_teams_t *parser(int ac, char **av)
{
    my_teams_t *res = NULL;

    if (ac == 2) {
        if (strncmp(av[1], "-help", 5) == 0)
            return usage();
        else if (atoi(av[1]) > 0) {
            res = malloc(sizeof(my_teams_t));
            res->server = malloc(sizeof(server_t));
            res->server->port = atoi(av[1]);
        } else {
            printf("Error: Bad usage.\n");
        }
    }
    return res;
}

int main(int ac, char **av)
{
    my_teams_t *teams = parser(ac, av);

    if (teams == NULL)
        return 84;
    init_teams_server(teams);
    start_teams_server(teams);
    close_server(teams);
    return 0;
}