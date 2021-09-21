/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../include/server.h"

int get_stor_datasock(myftp_t *ftp, client_t *client)
{
    unsigned int tmp_intsize = sizeof(struct sockaddr_in);
    int tmp_client_socket;
    struct sockaddr_in client_tmp = {0};

    tmp_client_socket = accept(client->data_socket,
        (struct sockaddr *)&client_tmp, &tmp_intsize);
    if (tmp_client_socket == -1) {
        return ERROR;
    }
    FD_SET(tmp_client_socket, &ftp->current_socket);
    return tmp_client_socket;
}

void stor_file(int datasock, int file)
{
    char tmp[256];
    int readchar;

    while ((readchar = read(datasock, tmp, 256)) == -1)
        readchar = read(datasock, tmp, 256);
    while (1) {
        if (readchar == -1)
            break;
        tmp[readchar] = '\0';
        dprintf(file, "%s", tmp);
        readchar = read(datasock, tmp, 256);
    }
    dprintf(datasock, "\n226 Closing data connection.\n");
    close(file);
    close(datasock);
}

int command_execute_stor(char *command, client_t *client, myftp_t *ftp)
{
    int datasock;
    int file;

    if (strncmp(command, "STOR ", 5) != 0)
        return 84;
    datasock = get_stor_datasock(ftp, client);
    command = strtok(command, "STOR ");
    command = strtok(command, "\n\r");
    dprintf(client->client_socket, "150 File status okay; about"
                                   " to open data connection.\n");
    if ((file = open(command, O_CREAT | O_APPEND | O_WRONLY, 0666)) == -1) {
        perror("open()");
        return 0;
    }
    stor_file(datasock, file);
    return 0;
}