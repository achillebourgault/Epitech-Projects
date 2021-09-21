/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

char *read_command(void)
{
    char *command;
    size_t bufsize = 32;
    int read;

    command = malloc(sizeof(char) * bufsize);
    if (command == NULL)
        return NULL;
    read = getline(&command, &bufsize, stdin);
    command[read] = '\0';
    return command;
}