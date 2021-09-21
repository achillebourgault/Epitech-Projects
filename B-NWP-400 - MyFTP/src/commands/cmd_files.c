/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "../../include/server.h"

int command_execute_dele(char *command, client_t *client, myftp_t *ftp)
{
    if (strncmp(command, "DELE ", 5) != 0)
        return 84;
    if (is_connected(client, 0) != 0)
        return 84;
    command = strtok(command, "DELE ");
    command = strtok(command, "\n\r");
    if (access(command, F_OK) == 0) {
        if (remove(command) != -1) {
            dprintf(client->client_socket,
                "250 Requested file action okay, completed.\n");
        } else
            dprintf(client->client_socket, "xxx Error\n");
    } else
        dprintf(client->client_socket, "xxx Error\n");
    return 0;
}

void retr_file(char *command, int datasock, myftp_t *ftp)
{
    FILE *file;
    int c;

    if ((file = fopen(command, "r")) != NULL) {
        c = fgetc(file);
        while (c != EOF && c != '\0') {
            dprintf(datasock, "%c", c);
            c = fgetc(file);
        }
        dprintf(datasock, "\n226 Closing data connection.\n");
        close(datasock);
        FD_CLR(datasock, &ftp->current_socket);
        fclose(file);
    }
}

int command_execute_retr(char *command, client_t *client, myftp_t *ftp)
{
    int datasock;
    struct sockaddr_in client_tmp = {0};
    unsigned int tmp_size = sizeof(struct sockaddr_in);

    if (strncmp(command, "RETR ", 5) != 0)
        return 84;
    datasock = accept(client->data_socket, (struct sockaddr *)&client_tmp,
        &tmp_size);
    if (datasock == -1) {
        perror("accept()");
        return 84;
    }
    command = strtok(command, "RETR ");
    command = strtok(command, "\n\r");
    dprintf(client->client_socket, "150 File status okay; about"
                                   " to open data connection.\n");
    retr_file(command, datasock, ftp);
    return 0;
}

char *create_command(client_t *client, char *command)
{
    char *res;
    int is_path = 1;
    char *path;

    if (strncmp(command, "LIST ", 5) == 0) {
        is_path = 0;
        command = strtok(command, "LIST ");
    } else
        command = strtok(command, "LIST");
    command = strtok(command, "\n\r");
    path = is_path == 0 ? strdup(command) : strdup(client->working_directory);
    res = malloc(sizeof(char) * (6 + strlen(path) + 1));
    strcat(res, "ls -l ");
    strcat(res, path);
    return res;
}

int command_execute_list(char *command, client_t *client, myftp_t *ftp)
{
    int r;
    char buffer[1024];
    FILE *ls;

    if ((strncmp(command, "LIST", 4) != 0 &&
        strncmp(command, "LIST ", 5) != 0) || is_connected(client, 0) != 0)
        return 84;
    ls = popen(create_command(client, command), "r");
    if (ls == NULL) {
        fprintf(stderr, "popen");
        exit(errno);
    }
    while ((r = fread(buffer, 1, sizeof(buffer) - 1, ls)) > 0)
        buffer[r] = '\0';
    dprintf(client->client_socket, "%s", buffer);
    pclose(ls);
    return 0;
}