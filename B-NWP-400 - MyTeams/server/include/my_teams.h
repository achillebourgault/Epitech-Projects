/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_MY_TEAMS_H
#define B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_MY_TEAMS_H

#include <sys/queue.h>
#include "types.h"
#include "string.h"
#include "stdlib.h"
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#include "../../libs/myteams/logging_server.h"

#define ERROR 84
#define MAX_CLIENTS 32
#define BUFSIZE 512

typedef struct server_s {
    int port;
    int socket;
    fd_set current_sockets;
    fd_set ready_sockets;
    teams_t **teams;
    user_t **users;
    channels_t **channels;
    threads_t **threads;
    discussion_t **discussion;
    int *cli_socket;
} server_t;

typedef struct my_teams_s {
    server_t *server;
} my_teams_t;

/* SERVER */
void init_teams_server(my_teams_t *teams);
int start_teams_server(my_teams_t *teams);
void close_server(my_teams_t *teams);

/* COMMANDS */
int cmd_login(char *buffer, my_teams_t *teams, int socket);
int cmd_logout(char *buffer, my_teams_t *teams, int socket);
int cmd_create_teams(char *buffer, my_teams_t *teams, int socket);
int cmd_create_channel(char *buffer, my_teams_t *teams, int socket);
int cmd_create_threads(char *buffer, my_teams_t *teams, int socket);
int cmd_create_reply(char *buffer, my_teams_t *teams, int socket);
int cmd_help(char *buffer, my_teams_t *teams, int socket);
int cmd_list_teams(char *buffer, my_teams_t *teams, int socket);
int cmd_list_channels(char *buffer, my_teams_t *teams, int socket);
int cmd_list_threads(char *buffer, my_teams_t *teams, int socket);
int cmd_list_replies(char *buffer, my_teams_t *teams, int socket);
int cmd_info_logged(char *buffer, my_teams_t *teams, int socket);
int cmd_info_team(char *buffer, my_teams_t *teams, int socket);
int cmd_info_channel(char *buffer, my_teams_t *teams, int socket);
int cmd_info_thread(char *buffer, my_teams_t *teams, int socket);
int cmd_messages(char *buffer, my_teams_t *teams, int socket);
int cmd_send(char *buffer, my_teams_t *teams, int socket);
int cmd_subscribe(char *buffer, my_teams_t *teams, int socket);
int cmd_subscribed(char *buffer, my_teams_t *teams, int socket);
int cmd_unsubscribe(char *buffer, my_teams_t *teams, int socket);
int cmd_use(char *buffer, my_teams_t *teams, int socket);
int cmd_users(char *buffer, my_teams_t *teams, int socket);
int cmd_user(char *buffer, my_teams_t *teams, int socket);

/* DATA */
void load_data(my_teams_t *my_team);
void load_data_beginning(my_teams_t *my_team);
void init_data();
teams_t **register_teams(char **teams_uuid);
user_t **register_users(char **users_uuid, int nb);
channels_t **register_channels(char **channels_uuid);
threads_t **register_threads(char **channels_uuid);
discussion_t **register_discussion(char **discuss_uuid);

/* UTILS */
void check_file(char *path);
char **get_all_files(char *path);
int get_total_files(char *path);
char *generate_uuid(void);
char **str_to_word_array(char *str, char *sep);
void handle_commands(my_teams_t *teams, int socket, char *buffer);
char *give_time();
char **get_array(char *label, char *filename);
user_t *get_user_by_uuid(char *uuid, user_t **users);
discussion_t *get_private_message_by_uuid(char *uuid_send, char *guest_uuid,
    discussion_t **private_discussion);
char *get_field(char *filename, char *field);
int get_array_size(char const *buffer);
char *clean_str(char const *str, char ban);
char *get_content_file(char *filename);

#endif