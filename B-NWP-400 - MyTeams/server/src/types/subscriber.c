/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/my_teams.h"

void add_new_subscriber(teams_t *team, char *user_uuid)
{
    int alloc = 1;
    user_t **update;

    for (; team->subscribers[alloc] != NULL; alloc++);
    update = malloc(sizeof(user_t *));
    update[0] = load_user(user_uuid, -42, 1);
    for (alloc = 1; team->subscribers[alloc] != NULL; alloc++)
        update[alloc] = load_user(team->subscribers[alloc - 1]->uuid,
            team->subscribers[alloc - 1]->cli_sock, 1);
    update[alloc] = NULL;
    team->subscribers = update;
}