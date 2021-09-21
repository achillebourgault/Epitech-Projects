/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myftp_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include "../include/server.h"

void info(myftp_t *ftp, int status, char *message)
{
    if (status == ERROR)
        fprintf(stderr, "%s", message);
    else
        printf("%s", message);
    close_ftp(ftp);
    exit(status);
}

void usage(myftp_t *ftp)
{
    char *a;

    a = strdup("USAGE: ./myftp port path\n    port is the port number on "
    "which the server socket listens\n    path is the path to the"
    " home directory for the Anonymous user\n");
    info(ftp, 0, a);
}

void check_errors(myftp_t *ftp)
{
    DIR *dir = opendir(ftp->path);

    printf("path: %s\nport: %s\n", ftp->path, ftp->port);
    if (dir) {
        closedir(dir);
    } else {
        fprintf(stderr, "myftp: Path is invalid.\n");
        close_ftp(ftp);
        exit(ERROR);
    }
    for (int i = 0; ftp->port[i]; i++) {
        if (!isdigit(ftp->port[i]))
            info(ftp, ERROR, "myftp: Port is invalid.\n");
    }
    if (atoi(ftp->port) < 0)
        info(ftp, ERROR, "myftp: Port is invalid.\n");
}

int parser(int ac, char **av, myftp_t *ftp)
{
    if (ac == 2) {
        if (!strstr(av[1], "-help")) {
            info(ftp, ERROR, "USAGE: ./myftp port path\n");
            exit(ERROR);
        } else {
            usage(ftp);
        }
    } else if (ac == 3) {
        ftp->port = strdup(av[1]);
        ftp->path = strdup(av[2]);
    } else {
        info(ftp, ERROR, "USAGE: ./myftp port path\n");
    }
    check_errors(ftp);
    return 0;
}

int main(int ac, char **av)
{
    struct myftp_s *myftp;

    myftp = new_ftp();
    parser(ac, av, myftp);
    ftp_server(myftp);
    close_ftp(myftp);
    return 0;
}