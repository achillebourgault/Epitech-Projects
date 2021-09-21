/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned num_digits(const unsigned n)
{
    if (n < 10)
        return 1;
    return 1 + num_digits(n / 10);
}

char *my_itoa(int nb)
{
    int len = num_digits(nb);
    int i = len - 1;
    char *str = malloc(sizeof(char) * (len + 1));

    for (i; i >= 0; i--) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[len] = '\0';
    return (str);
}

char *give_time(void)
{
    time_t count = (long int)time(NULL);
    char *to_ret = my_itoa(count);

    return (to_ret);
}