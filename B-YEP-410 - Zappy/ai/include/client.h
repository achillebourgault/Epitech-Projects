/*
** EPITECH PROJECT, 2024
** ai
** File description:
** Created by Frédéric Lawecki--Walkowiak
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <sys/select.h>

#define ERROR 84
#define SUCCESS 1
#define BUFSIZE 4096
#define TRUE 0

typedef struct parser_s {
    int port;
    char *machine_name;
    char *team_name;
} parser_t;

typedef struct client_s {
    char *server_ip;
    char *team_name;
    int server_port;
    int socket;
    int exit;
    int level;
    int tmp_inv[7];
    int dir_has_changed;
    int pickup;
    fd_set current_sockets;
    fd_set ready_sockets;
} client_t;

int connect_client_to_server(client_t *client);
void client_loop(client_t *client);
char *read_request(int socket);
void *safe_malloc(unsigned long size);
int error(const char *message);
parser_t *parse_server(int ac, char **av);
parser_t *parser(char **av);
char **str_to_word_array(char *str, char *sep);
char *clean_str(char const *str, char ban);
void handle_action(client_t *client, char *request);
void run_ai(client_t *client, char *request);

#endif //CLIENT_H