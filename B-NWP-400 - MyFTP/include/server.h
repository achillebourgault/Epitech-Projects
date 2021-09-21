/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_NWP_400_LIL_4_1_MYFTP_ACHILLE_BOURGAULT_SERVER_H
#define B_NWP_400_LIL_4_1_MYFTP_ACHILLE_BOURGAULT_SERVER_H

#define ERROR 84
#define MAX_CLIENTS 30

#include "client.h"
#include <netinet/ip.h>
#include <stdio.h>
#ifdef __APPLE__
    #include <pcap.h>
#elif __linux__
    #include <sys/socket.h>
#endif

typedef struct myftp_s {
    char *port;
    char *path;
    char *user;
    char *passwd;
    char **query;
    int isAvailible;
    int server;
    fd_set current_socket;
    fd_set ready_sockets;
    int client_counts;
    client_t *current_clients[MAX_CLIENTS];
    struct sockaddr_in *server_interface;
    int data_port;
    int command_port;
    void (*commands[14])();
} myftp_t;

myftp_t *new_ftp();
void ftp_server(myftp_t *ftp);
void init_server_socket(myftp_t *ftp);
void close_ftp(myftp_t *ftp);
void info(myftp_t *ftp, int status, char *message);
int get_stor_datasock(myftp_t *ftp, client_t *client);

//utils
int get_nb_char(const char *str, char c);
char *clean_str(const char *str, char c);
int get_new_id(myftp_t *ftp);

client_t *new_client(myftp_t *ftp, int csock, int sinsize);

int enable_passive_mode(char *command, client_t *client, myftp_t *ftp);
int enable_active_mode(char *command, client_t *client, myftp_t *ftp);
int get_client_id_from_socket(myftp_t *ftp, int socket);
void handle_commands(myftp_t *ftp, client_t *client);

int command_execute_user(char *command, client_t *client, myftp_t *ftp);
int command_execute_passwd(char *command, client_t *client, myftp_t *ftp);
int command_execute_cwd(char *command, client_t *client, myftp_t *ftp);
int command_execute_cdup(char *command, client_t *client, myftp_t *ftp);
int command_execute_pwd(char *command, client_t *client, myftp_t *ftp);
int command_execute_dele(char *command, client_t *client, myftp_t *ftp);
int command_execute_retr(char *command, client_t *client, myftp_t *ftp);
int command_execute_stor(char *command, client_t *client, myftp_t *ftp);
int command_execute_list(char *command, client_t *client, myftp_t *ftp);
int command_execute_quit(char *command, client_t *client, myftp_t *ftp);
int command_execute_noop(char *command, client_t *client, myftp_t *ftp);
int command_execute_help(char *command, client_t *client, myftp_t *ftp);
int unknown_command(char *command, client_t *client, myftp_t *ftp);

#endif