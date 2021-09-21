/*
** EPITECH PROJECT, 2024
** dev_save
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/types.h"
#include "../../include/my_teams.h"

void save_user(user_t *user)
{
    FILE *file;
    char filename[49] = ".data/users/";

    strcat(filename, user->uuid);
    if ((file = fopen(filename, "w"))) {
        fprintf(file, "name:%s;\n", user->name);
        fprintf(file, "connected:%d;\n", user->connected);
        fprintf(file, "socket:%d;\n", user->cli_sock);
    }
    fclose(file);
}

user_t *create_user(char *name, int socket)
{
    user_t *user = malloc(sizeof(user_t));

    user->cli_sock = socket;
    user->uuid = generate_uuid();
    user->name = strdup(name);
    user->connected = 0;
    save_user(user);
    return user;
}

user_t *load_user(char *uuid, int cli_sock, int nb)
{
    (void)cli_sock;
    FILE *file;
    user_t *user = malloc(sizeof(user_t));
    char filename[49] = ".data/users/";

    strcat(filename, uuid);
    if ((file = fopen(filename, "r"))) {
        user->connected = nb == 0 ? 0 : atoi(get_field(filename, "connected:"));
        user->cli_sock = atoi(get_field(filename, "socket:"));
        user->uuid = uuid;
        user->name = get_field(filename, "name:");
        if (nb == 0)
            server_event_user_loaded(uuid, user->name);
        fclose(file);
        save_user(user);
    } else
        printf("ERROR: Cannot load user #%s\n", uuid);
    return user;
}