/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/
#ifndef B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_MYTEAMS_CLIENT_H
#define B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_MYTEAMS_CLIENT_H

#include <sys/select.h>
#include "../../libs/myteams/logging_client.h"

#define ERROR 84
#define SUCCESS 1
#define MAX_ARGUMENTS 4
#define COMMAND_COUNT 16
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define BUFSIZE 4096
#define EVENTS_COUNT 4

typedef struct {
    char *server_ip;
    int server_port;
    int socket;
    int connected;
    char *username;
    char *user_uid;
    char **use;
    fd_set current_sockets;
    fd_set ready_sockets;
} client_t;

int connect_to_server(client_t *client);
char *read_command(void);
int client_loop(client_t *client);
void handle_command(client_t *client, char **request);
char **command_splitter(char *command);
char *strdup_bounds(char *str, int in, int out);
void send_request(client_t *client, char *code, char **arg_list);
char **str_to_word_array(char *str, char *sep);
char **get_request(client_t *client);
void clean_str(char *str, char to_remove);
char **create_logout_arglist(char *uid);
void handle_logout_request(client_t *client, char **reply);

int cmd_use(client_t *client, char **command);
int cmd_exit(client_t *client, char **command);
int cmd_help(client_t *client, char **command);
int cmd_info(client_t *client, char **command);
int cmd_list(client_t *client, char **command);
int cmd_send(client_t *client, char **command);
int cmd_user(client_t *client, char **command);
int cmd_login(client_t *client, char **command);
int cmd_users(client_t *client, char **command);
int cmd_create(client_t *client, char **command);
int cmd_logout(client_t *client, char **command);
int cmd_messages(client_t *client, char **command);
int cmd_subscribe(client_t *client, char **command);
int cmd_subscribed(client_t *client, char **command);
int cmd_unsubscribe(client_t *client, char **command);
int cmd_unknown(client_t *client, char **command);

void handle_request(client_t *client, char **command_array);
int event_private_msg(client_t *client, char **command);
int event_login(client_t *client, char **command);
int event_logout(client_t *client, char **command);
int event_unknown(client_t *client, char **command);



#endif //B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_MYTEAMS_CLIENT_H