/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#include "../../include/my_teams.h"

int cmd_list_teams(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "650") != 0)
        return (1);
    return 1;
}

int cmd_list_channels(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "660") != 0)
        return (1);
    return 1;
}

int cmd_list_threads(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "670") != 0)
        return (1);
    return 1;
}

int cmd_list_replies(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");

    if (strcmp(tab[0], "680") != 0)
        return (1);
    return 1;
}
