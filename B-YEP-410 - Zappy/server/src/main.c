/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../include/types/elevation.h"
#include "../include/server.h"

int help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height ");
    printf(" -n name1 name2 ... -c clientsNb -f freq\n");
    printf("\tport\t is the port number\n");
    printf("\twidth\t is the width of the world\n");
    printf("\theight\t is the height of the world\n");
    printf("\tnameX\t is the name of the team X\n");
    printf("\tclientsNb\t is the number of authorized clients per team\n");
    printf(
        "\tfreq\t is the reciprocal of time unit for execution of actions\n");
    return 0;
}

int main(int ac, char **av)
{
    parser_t *parser = parse_server(ac, av);
    server_t *server = init_server(parser);

    server_loop(server);
    free(parser);
    free(server->world);
    return 0;
}