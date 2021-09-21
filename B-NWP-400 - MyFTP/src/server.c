/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/server.h"

myftp_t *new_ftp()
{
    myftp_t *res = malloc(sizeof(myftp_t));

    res->query = NULL;
    res->port = NULL;
    res->path = NULL;
    res->user = NULL;
    res->passwd = NULL;
    res->isAvailible = -1;
    res->client_counts = 0;
    for (int i = 0; i < MAX_CLIENTS; i++)
        res->current_clients[i] = NULL;
    return res;
}

void accept_connexion(myftp_t *ftp)
{
    struct sockaddr_in csin = {0};
    int csock;
    int sinsize = sizeof(csin);

    csock = accept(ftp->server, (struct sockaddr *)&csin,
        (socklen_t *)&sinsize);
    FD_SET(csock, &ftp->current_socket);
    if (csock == -1)
        exit(84);
    if (get_new_id(ftp) == -1)
        return;
    ftp->current_clients[get_new_id(ftp)] = new_client(ftp, csock, sinsize);
    ftp->client_counts++;
    dprintf(csock, "220 (vsFTPd 3.0.0)\n");
}

int get_client_id_from_socket(myftp_t *ftp, int socket)
{
    int res = 0;

    for (int x = 0; x != ftp->client_counts; x++) {
        if (ftp->current_clients[x] != NULL &&
            ftp->current_clients[x]->client_socket == socket) {
            res = x;
            break;
        }
    }
    return res;
}

void ftp_server(myftp_t *ftp)
{
    init_server_socket(ftp);

    while (ftp->isAvailible != -1) {
        ftp->ready_sockets = ftp->current_socket;
        if (select(FD_SETSIZE, &ftp->ready_sockets, NULL, NULL, NULL) < 0) {
            perror("select()");
            exit(ERROR);
        }
        for (int i = 0; i != FD_SETSIZE; i++) {
            if (FD_ISSET(i, &ftp->ready_sockets)) {
                if (i == ftp->server) {
                    accept_connexion(ftp);
                } else {
                    handle_commands(ftp,
                        ftp->current_clients[get_client_id_from_socket(ftp,
                            i)]);
                }
            }
        }
    }
}

void close_ftp(myftp_t *ftp)
{
    if (ftp->port)
        free(ftp->port);
    if (ftp->path)
        free(ftp->path);
    if (ftp->user)
        free(ftp->user);
    if (ftp->passwd)
        free(ftp->passwd);
    if (ftp->query != NULL)
        free(ftp->query);
}