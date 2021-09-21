/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include "../include/server.h"

void init_server_socket(myftp_t *ftp)
{
    int server = socket(AF_INET, SOCK_STREAM, 0);

    if (server == -1)
        exit(errno);
    ftp->server = server;
    struct sockaddr_in sin = {0};
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(atoi(ftp->port));
    if (bind(server, (struct sockaddr *)&sin, sizeof(sin)) == -1)
        exit(errno);
    if (listen(ftp->server, 5) == -1)
        exit(errno);
    ftp->client_counts = 0;
    ftp->isAvailible = 0;
    FD_ZERO(&ftp->current_socket);
    FD_SET(ftp->server, &ftp->current_socket);
}