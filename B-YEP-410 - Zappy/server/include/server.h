/*
** EPITECH PROJECT, 2024
** B_YEP_410_LIL_4_1_zappy_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_YEP_410_LIL_4_1_ZAPPY_ACHILLE_BOURGAULT_SERVER_H
#define B_YEP_410_LIL_4_1_ZAPPY_ACHILLE_BOURGAULT_SERVER_H

#include "constants.h"
#include "world.h"
#include "types/team.h"
#include "inventory.h"
#include "vision.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define DEBUG_MODE 1
#define MAX_CLIENTS 64
#define ERROR 84
#define SUCCESS 1
#define BUFSIZE 512
#define COMMAND_COUNT 39

typedef struct config_s {
    int max_players_team;
    int freq;
} config_t;

typedef struct item_s {
    int type;
} item_t;

typedef struct player_s {
    int level;
    inventory_t *inventory;
    vision_t *vision;
    int pos[2];
    int time_units;
    int socket;
    int action;
} player_t;

typedef struct tile_s {
    int pos[2];
    item_t **items;
    player_t **players;
} tile_t;

typedef struct world_s {
    int dimensions[2];
    tile_t ***map;
} world_t;


typedef struct team_s {
    int id;
    const char *name;
    player_t **players;
    int color[3];
} team_t;

typedef struct parser_s {
    int port;
    int width;
    int height;
    char **team_names;
    int clientsNb;
    int freq;
} parser_t;

typedef struct server_s {
    int port;
    int socket;
    int quit;
    fd_set current_sockets;
    fd_set ready_sockets;
    world_t *world;
    player_t *player;
    config_t *config;
    team_t *teams[CONFIG_MAX_TEAMS];
    int team_colors[CONFIG_MAX_TEAMS][3];
    int *sock_array;
} server_t;

/* PLAYER */
player_t *create_player(int socket, int dimensions[2], server_t *server);
void free_player(player_t *player);

/* INVENTORY */
inventory_t *init_inventory();
void add_item_to_inventory(player_t *player, int item, int quantity);
void use_item(player_t *player, int item, int quantity);

server_t *init_server(parser_t *parser);
int init_network(server_t *server);
void server_loop(server_t *server);

/* ACTIONS */
void move(server_t *server, player_t *player, int direction);
void broadcast(player_t **players, char *message);

char *get_inventory_data(player_t *player);

item_t *create_item(int type);

void create_team(server_t *server, char *name, int id);
void join_team(server_t *server, player_t *player, team_t *team);
int get_team_color(server_t *server);

/* UTILS */
int random_nbr(int min, int max);
int error(const char *message);
int is_flag(char *arg);
int check_arguments(parser_t *res);
void *safe_malloc(unsigned long size);
void debug(int socket, char *print);
team_t *get_team_by_name(server_t *server, char *name);
char **str_to_word_array(char *str, char *sep);
char *clean_str(char const *str, char ban);
char *my_itoa(int nb);
char *read_request(int socket);

int player_contains_at_least(player_t *player, int item, int nb);
int get_total_players(server_t *server);

parser_t *parser(char **av);
parser_t *parse_server(int ac, char **av);

player_t **get_all_players(server_t *server);
player_t *get_player_by_index(player_t **players, int index);
player_t *get_player_by_socket(server_t *server, int socket);
team_t *get_team_by_player(server_t *server, player_t *p);

int help();
void free_array(void **array);

//COMMANDS
int login_player(server_t *server, char *team_name, int socket);
int vzr_lgn(server_t *server, int socket);
int cmd_unknown(server_t *server, char **command, int socket);
int cmd_msz(server_t *server, char **command, int socket);
int cmd_bct(server_t *server, char **command, int socket);
int cmd_mct(server_t *server, char **command, int socket);
int cmd_tna(server_t *server, char **command, int socket);
int cmd_ppo(server_t *server, char **command, int socket);
int cmd_plv(server_t *server, char **command, int socket);
int cmd_pin(server_t *server, char **command, int socket);
int cmd_pex(server_t *server, char **command, int socket);
int cmd_pbc(server_t *server, char **command, int socket);
int cmd_pic(server_t *server, char **command, int socket);
int cmd_pie(server_t *server, char **command, int socket);
int cmd_pfk(server_t *server, char **command, int socket);
int cmd_pdr(server_t *server, char **command, int socket);
int cmd_pgt(server_t *server, char **command, int socket);
int cmd_pdi(server_t *server, char **command, int socket);
int cmd_enw(server_t *server, char **command, int socket);
int cmd_eht(server_t *server, char **command, int socket);
int cmd_ebo(server_t *server, char **command, int socket);
int cmd_edi(server_t *server, char **command, int socket);
int cmd_sgt(server_t *server, char **command, int socket);
int cmd_sst(server_t *server, char **command, int socket);
int cmd_seg(server_t *server, char **command, int socket);
int cmd_smg(server_t *server, char **command, int socket);
int cmd_suc(server_t *server, char **command, int socket);
int cmd_sbp(server_t *server, char **command, int socket);
int cmd_forward(server_t *server, char **command, int socket);
int cmd_right(server_t *server, char **command, int socket);
int cmd_left(server_t *server, char **command, int socket);
int cmd_look(server_t *server, char **command, int socket);
int cmd_inventory(server_t *server, char **command, int socket);
int cmd_broadcast_text(server_t *server, char **command, int socket);
int cmd_connect_nbr(server_t *server, char **command, int socket);
int cmd_fork(server_t *server, char **command, int socket);
int cmd_eject(server_t *server, char **command, int socket);
int cmd_take_object(server_t *server, char **command, int socket);
int cmd_incantation(server_t *server, char **command, int socket);
int cmd_vzr_plrs(server_t *server, char **command, int socket);
int cmd_set_object(server_t *server, char **command, int socket);

int *get_items_in_tile(tile_t *tile);
int get_item_count_in_tile(tile_t *tile, int item_type);

vision_t *init_vision(int direction, server_t *server, player_t *player);

void add_player_to_tile(player_t *player, tile_t *tile);
void remove_player_to_tile(player_t *item, tile_t *tile);
world_t *generate_world(const int dimensions[2]);
void generate_ressources(world_t *world);
tile_t *init_tile(const int pos[2]);
void add_ressource_to_tile(item_t *item, tile_t *tile);
int tile_contains_item(item_t *item, int nb, tile_t *tile);
tile_t *get_tile_by_pos(const int pos[2], world_t *world);
void remove_ressource_to_tile(item_t *item, tile_t *tile);

char *get_content_on_tile(tile_t *tile);

int **get_pos_array_ns(server_t *server, player_t *p);
int **get_pos_array_x(server_t *server, player_t *p);
char *look_func(server_t *server, player_t *p);

int get_id_by_name(char *name);
int get_parameter(parser_t *parser, char **av, char *flag, int i);
char **get_teams_names(char **av, int i);
char *get_item_name_by_type(int type);

#endif