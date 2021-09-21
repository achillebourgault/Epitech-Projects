/*
** EPITECH PROJECT, 2024
** myteams_cli
** File description:
** Created by Achille Bourgault
*/

#include "../../include/my_teams.h"

teams_t **register_teams(char **teams_uuid)
{
    teams_t **teams;
    int alloc;

    for (alloc = 0; teams_uuid[alloc] != NULL; alloc++);
    teams = malloc(sizeof(teams_t *) * (alloc + 1));
    for (alloc = 0; teams_uuid[alloc]; alloc++)
        teams[alloc] = load_team(teams_uuid[alloc]);
    teams[alloc] = NULL;
    return teams;
}

user_t **register_users(char **users_uuid, int nb)
{
    user_t **users;
    int alloc;

    for (alloc = 0; users_uuid[alloc] != NULL; alloc++);
    users = malloc(sizeof(user_t *) * (alloc + 1));
    for (alloc = 0; users_uuid[alloc]; alloc++)
        users[alloc] = load_user(users_uuid[alloc], 0, nb);
    users[alloc] = NULL;
    return users;
}

discussion_t **register_discussion(char **discussion_uuid)
{
    discussion_t **discussion;
    int alloc;

    for (alloc = 0; discussion_uuid[alloc] != NULL; alloc++);
    discussion = malloc(sizeof(user_t *) * (alloc + 1));
    for (alloc = 0; discussion_uuid[alloc]; alloc++)
        discussion[alloc] = load_discussion(discussion_uuid[alloc]);
    discussion[alloc] = NULL;
    return discussion;
}

channels_t **register_channels(char **channels_uuid)
{
    channels_t **channels;
    int alloc;

    for (alloc = 0; channels_uuid[alloc] != NULL; alloc++);
    channels = malloc(sizeof(teams_t *) * (alloc + 1));
    for (alloc = 0; channels_uuid[alloc]; alloc++)
        channels[alloc] = load_channel(channels_uuid[alloc]);
    channels[alloc] = NULL;
    return channels;
}

threads_t **register_threads(char **channels_uuid)
{
    threads_t **channels;
    int alloc;

    for (alloc = 0; channels_uuid[alloc] != NULL; alloc++);
    channels = malloc(sizeof(teams_t *) * (alloc + 1));
    for (alloc = 0; channels_uuid[alloc]; alloc++)
        channels[alloc] = load_thread(channels_uuid[alloc]);
    channels[alloc] = NULL;
    return channels;
}