/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include "../include/myteams_client.h"
#include <stdlib.h>
#include <string.h>

char *strdup_bounds(char *str, int in, int out)
{
    int length = out - in;
    char *res = malloc(sizeof(char) * (length + 1));
    int j = 0;

    while (in != out) {
        res[j] = str[in];
        in++;
        j++;
    }
    res[j] = '\0';
    return res;
}

int find_next_separator(char *str, char separator, int pos)
{
    int i = pos + 1;

    for (i; str[i] != '\0'; i++) {
        if (str[i] ==  separator)
            return i;
    }
    return i;
}

char *get_command(char *str, int in, int out)
{
    char *res = malloc(sizeof(char) * (out - in + 1));

    if (res == NULL)
        return NULL;
    res = strdup_bounds(str, in, out);
}

void clean_str(char *str, char to_remove)
{
    char *dest = str;
    char *source = dest;

    for (source; *source != '\0'; source++) {
        *dest = *source;
        if (*dest != to_remove)
            dest++;
    }
    *dest = '\0';
}

char **command_splitter(char *command)
{
    char **res = malloc(sizeof(*res) * (MAX_ARGUMENTS + 1));
    int in = 0;
    int out = find_next_separator(command, ' ', 0);
    int arg = 0;

    res[arg] = get_command(command, in, out);
    clean_str(res[arg], '\n');
    arg++;
    if (command[out] != '\0') {
        while (command[out + 1] != '\0') {
            in = find_next_separator(command, '"', out);
            out = find_next_separator(command, '"', in);
            res[arg] = strdup_bounds(command, in, out + 1);
            clean_str(res[arg], '\n');
            out++;
            arg++;
        }
    }
    res[arg] = NULL;
    return res;
}