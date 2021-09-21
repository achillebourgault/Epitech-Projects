/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <printf.h>
#include "../../include/my_teams.h"

int cmd_messages(char *buffer, my_teams_t *teams, int socket)
{
    char **tab = str_to_word_array(buffer, "<SP>");
    char *to_send;

    if (strcmp("350", tab[0]) != 0)
        return (1);
    return 1;
}