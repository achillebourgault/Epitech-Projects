/*
** EPITECH PROJECT, 2024
** B-YEP-410-LIL-4-1-zappy-achille.bourgault
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#include <string.h>
#include "visualizer.h"

gui_t *init_gui(parser_t *parser)
{
    gui_t *res = safe_malloc(sizeof(gui_t));

    res->config = safe_malloc(sizeof(config_t));
    res->config->machine_name = strdup(parser->machine_name);
    res->config->port = parser->port;
    return res;
}

int main(int ac, char **av)
{
    parser_t *parser = parse_server(ac, av);
    gui_t *gui = init_gui(parser);

    connect_client_to_server(gui);
    open_gui(gui);
    return 0;
}