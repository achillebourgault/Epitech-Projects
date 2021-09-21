/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/server.h"

int command_execute_quit(char *command, client_t *client, myftp_t *ftp)
{
    if (strncmp(command, "QUIT", 4) != 0)
        return 84;
    dprintf(client->client_socket, "221 Goodbye.\n");
    client->connected = 1;
    close(client->client_socket);
    ftp->current_clients[get_client_id_from_socket(ftp,
        client->client_socket)] = NULL;
    FD_CLR(client->client_socket, &ftp->current_socket);
    ftp->client_counts -= 1;
    return 0;
}

int command_execute_noop(char *command, client_t *client, myftp_t *ftp)
{
    if (strncmp(command, "NOOP", 4) != 0)
        return 84;
    return 0;
}

int command_execute_help(char *command, client_t *client, myftp_t *ftp)
{
    if (strncmp(command, "HELP", 4) != 0)
        return 84;
    dprintf(client->client_socket,
        "214-The following commands are recognized.\n");
    dprintf(client->client_socket,
        " ABOR ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV FEAT");
    dprintf(client->client_socket, " HELP LIST MDTM MKD\n");
    dprintf(client->client_socket,
        " MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN");
    dprintf(client->client_socket, " REST RETR RMD  RNFR\n");
    dprintf(client->client_socket,
        " RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST TYPE");
    dprintf(client->client_socket, " USER XCUP XCWD XMKD\n");
    dprintf(client->client_socket, " XPWD XRMD\n");
    dprintf(client->client_socket, "214 Help OK.\n");
    return 0;
}

int unknown_command(char *command, client_t *client, myftp_t *ftp)
{
    if (is_connected(client, 1) == 0)
        dprintf(client->client_socket, "500 Unknown command.\n");
    return 0;
}