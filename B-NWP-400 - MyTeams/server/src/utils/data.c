/*
** EPITECH PROJECT, 2024
** dev_save
** File description:
** Created by Achille Bourgault
*/

#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include "../../include/types.h"
#include "../../include/my_teams.h"

void init_data(void)
{
    if (opendir(".data") != NULL)
        return;
    mkdir(".data", 0700);
    mkdir(".data/users", 0700);
    mkdir(".data/channels", 0700);
    mkdir(".data/teams", 0700);
    mkdir(".data/threads", 0700);
    mkdir(".data/messages", 0700);
    mkdir(".data/mp", 0700);
}

void load_data(my_teams_t *my_team)
{
    char **users_uuid = get_all_files(".data/users");
    char **teams_uuid = get_all_files(".data/teams");
    char **threads_uuid = get_all_files(".data/threads");
    char **channels_uuid = get_all_files(".data/channels");
    char **discuss_uuid = get_all_files(".data/mp");

    my_team->server->teams = register_teams(teams_uuid);
    my_team->server->users = register_users(users_uuid, 1);
    my_team->server->channels = register_channels(channels_uuid);
    my_team->server->threads = register_threads(threads_uuid);
    my_team->server->discussion = register_discussion(discuss_uuid);
}

void load_data_beginning(my_teams_t *my_team)
{
    char **users_uuid = get_all_files(".data/users");
    char **teams_uuid = get_all_files(".data/teams");
    char **threads_uuid = get_all_files(".data/threads");
    char **channels_uuid = get_all_files(".data/channels");
    char **discuss_uuid = get_all_files(".data/mp");

    my_team->server->teams = register_teams(teams_uuid);
    my_team->server->users = register_users(users_uuid, 0);
    my_team->server->channels = register_channels(channels_uuid);
    my_team->server->threads = register_threads(threads_uuid);
    my_team->server->discussion = register_discussion(discuss_uuid);
}