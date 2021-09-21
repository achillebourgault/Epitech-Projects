/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_NWP_400_LIL_4_1_MYFTP_ACHILLE_BOURGAULT_CLIENT_H
#define B_NWP_400_LIL_4_1_MYFTP_ACHILLE_BOURGAULT_CLIENT_H

typedef struct client_t {
    char *parent_directory;
    char *working_directory;
    int client_socket;
    char *param_user;
    int connected;
    char *param_passwd;
    int data_socket;
} client_t;

int is_connected(client_t *client, int msg);

char **get_files(char *path, int include_misc);
#endif