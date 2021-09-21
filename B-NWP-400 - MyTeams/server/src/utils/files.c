/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/my_teams.h"

char **get_array(char *label, char *filename)
{
    char *buffer = strdup(clean_str(clean_str
            (strstr(get_content_file(filename), label), '\n'), '\t'));
    char **res = malloc(sizeof(char *) *
        (get_array_size(strstr(get_content_file(filename), label)) + 2));
    char tmp[36];
    int cpt = 0;

    buffer += strlen(label);
    for (int i = 0, x = 0, cpt2 = 0; buffer[i] != '\0'; i++) {
        for (cpt2 = 0, x = i; buffer[x] != ';'; x++, cpt2++)
            tmp[cpt2] = buffer[x];
        if (buffer[x] == ';') {
            tmp[cpt2] = '\0'; res[cpt] = strdup(tmp);
            if (buffer[x + 1] != '\0')
                i += 36;
            else
                break;
            cpt++;
        }
    }
    res[cpt + 1] = NULL; return res;
}

char *get_content_file(char *filename)
{
    char *buffer = NULL;
    long length;
    FILE *f = fopen(filename, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(sizeof(char) * (length + 1));
        fread(buffer, 1, length, f);
        buffer[length] = '\0';
        fclose(f);
    }
    return buffer;
}

char *clean_str(char const *str, char ban)
{
    char *res;
    int x = 0;
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ban)
            x++;
    }
    res = malloc(sizeof(char) * (strlen(str) - x + 1));
    for (x = 0; str[x] != '\0'; x++) {
        if (str[x] == ban)
            continue;
        res[cpt] = str[x];
        cpt++;
    }
    res[cpt] = '\0';
    return res;
}

int get_array_size(char const *buffer)
{
    int cpt = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ';') {
            cpt++;
            if (buffer[i + 1] == '\0')
                break;
            i++;
        }
    }
    return cpt;
}

char *get_field(char *filename, char *field)
{
    int size;
    char *buffer = strdup(get_content_file(filename));
    char *res = NULL;

    buffer = clean_str(buffer, '\t');
    buffer = clean_str(buffer, '\n');
    if (strstr(buffer, field) == NULL)
        return res;
    for (int i = 0; buffer[i] != '\0' && strlen(buffer) <= strlen(field) &&
        strncmp(field, buffer, strlen(field)) != 0; i++, buffer++);
    buffer = strstr(buffer, field);
    buffer += strlen(field);
    for (size = 0; buffer[size] != '\0' && buffer[size] != ';'; size++);
    res = strndup(buffer, size);
    return res;
}