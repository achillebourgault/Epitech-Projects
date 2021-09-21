/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <string.h>
#include <stdlib.h>
#include "my_teams.h"

int nb_sep(char *str, char *sep)
{
    int count = 0;
    int sep_len = strlen(sep) - 1;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        for (; str[i] == sep[j]; j++) {
            if (j == sep_len) {
                count++;
                j = 0;
            }
        }
    return (count);
}

void str_to_word_array_sec(char *str, int bg, char ***tab, int *count)
{
    (*tab)[(*count)] = malloc(sizeof(char) * bg + 1);
    int i = 0;

    for (; i < bg; i++)
        (*tab)[(*count)][i] = str[i];
    (*tab)[(*count)][i] = '\0';
    (*count)++;
}

char *modif_str(char *str, int i)
{
    int j = 0;
    char *buffer = malloc(sizeof(char) * (strlen(str) - i + 1));

    for (; i < strlen(str); i++) {
        buffer[j] = str[i];
        j++;
    }
    buffer[j] = '\0';
    return (buffer);
}

char **str_to_word_array(char *str, char *sep)
{
    char **tab = malloc(sizeof(char *) * (nb_sep(str, sep) + 2));
    int count = 0;
    int bg = 0;
    int i = 0;
    int j = 0;

    for (; str[i] != '\0'; i++)
        for (; str[i] == sep[j]; j++)
            if (j == (strlen(sep) - 1)) {
                bg = i - (strlen(sep) - 1);
                str_to_word_array_sec(str, bg, &tab, &count);
                str = modif_str(str, i + 1);
                i = 0;
                j = 0;
            }
    tab[count] = strdup(str);
    tab[count + 1] = NULL;
    return (tab);
}