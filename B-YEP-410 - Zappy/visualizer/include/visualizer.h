/*
** EPITECH PROJECT, 2024
** B-YEP-410-LIL-4-1-zappy-achille.bourgault
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <sys/select.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "constants.h"

#define SUCCESS 1
#define BUFF_LIMIT 100

typedef struct parser_s {
    int port;
    char *machine_name;
    char *team_name;
} parser_t;

typedef struct player_s {
    int pos[2];
    int level;
    sfColor team_color;
    char *team_name;
} player_t;

typedef struct ressource_s {
    int pos[2];
    int type;
} ressource_t;

typedef struct config_s {
    int port;
    int socket;
    fd_set current_sockets;
    fd_set ready_sockets;
    char *machine_name;
} config_t;

typedef struct tile_s {
    sfRectangleShape *tile;
    sfCircleShape *circle;
    int pos[2];
    sfColor color;
    float o_x;
    float o_y;

    sfCircleShape *food_r;
    sfCircleShape *linemate_r;
    sfCircleShape *deraumere_r;
    sfCircleShape *sibur_r;
    sfCircleShape *mendiane_r;
    sfCircleShape *phiras_r;
    sfCircleShape *thystame_r;

    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} tile_t;

typedef struct gui_s {
    int map_size[2];
    int zoom;
    int camera_pos[2];
    config_t *config;
    ressource_t **ressources;
    player_t **players;
    sfRenderWindow *window;
    sfRectangleShape *rec_shapes[BUFF_LIMIT];
    sfSprite *sprites_obj[BUFF_LIMIT];
    tile_t ***tiles;
} gui_t;

/* GUI */
void open_gui(gui_t *gui);
int connect_client_to_server(gui_t *gui);
player_t *init_player(char *team_name, int pos[2], int color[3]);
ressource_t *init_ressource(int type, int pos[2]);

void init_tiles(gui_t *gui);
tile_t *init_tile(gui_t *gui, int pos[2], float pos2[2], float tile_size[2]);

void update_data(gui_t *gui);
ressource_t **get_all_ressources(gui_t *gui);
player_t ** get_all_players(gui_t *gui);
void draw(gui_t *gui);
void draw_player(gui_t *gui);
player_t **get_player_on_tile(gui_t *gui, tile_t *tile);

/* UTILS */
int random_nbr(int min, int max);
int error(const char *message);
int is_flag(char *arg);
int check_arguments(parser_t *res);
void *safe_malloc(unsigned long size);
char **str_to_word_array(char *str, char *sep);
char *clean_str(char const *str, char ban);

/* PARSER */
parser_t *parser(char **av);
parser_t *parse_server(int ac, char **av);

/* REQUESTS */
char *read_request(gui_t *gui);
void send_login_request(gui_t *gui);

/* FOOD & ROCKS */
void print_linemate(gui_t *gui, int y, int x);
void print_deraumere(gui_t *gui, int y, int x);
void print_sibur(gui_t *gui, int y, int x);
void print_mendiane(gui_t *gui, int y, int x);
void print_phiras(gui_t *gui, int y, int x);

/* CAM + VISUALIZER */

void gameloop(gui_t *gui);
void catch_camera_movement(gui_t *gui, sfEvent event);
void init_visualizer(gui_t *gui);

#endif //VISUALIZER_H