/*
** EPITECH PROJECT, 2024
** dev_save
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/my_teams.h"

void save_team(teams_t *team)
{
    FILE *file;
    char filename[49] = ".data/teams/";

    strcat(filename, team->uuid);
    if ((file = fopen(filename, "w"))) {
        fprintf(file, "name:%s;\n", team->name);
        fprintf(file, "description:%s;\n", team->description);
        fprintf(file, "channels:\n");
        if (team->channels != NULL)
            for (int x = 0; team->channels[x] != NULL; x++)
                fprintf(file, "\t%s;\n", team->channels[x]->uuid);
        fprintf(file, "subscribers:\n");
        if (team->subscribers != NULL)
            for (int x = 0; team->subscribers[x] != NULL; x++)
                fprintf(file, "\t%s;\n", team->subscribers[x]->uuid);
        fclose(file);
    }
}

teams_t *create_team(char *name, char *uuid, char *description)
{
    teams_t *team = malloc(sizeof(teams_t));

    team->uuid = generate_uuid();
    team->name = strdup(name);
    team->description = strdup(description);
    team->subscribers = malloc(sizeof(user_t *));
    team->subscribers[0] = NULL;
    team->channels = malloc(sizeof(channels_t *));
    team->channels[0] = NULL;
    server_event_team_created(team->uuid, team->name, uuid);
    save_team(team);
    return team;
}

channels_t **get_channels(char *filename)
{
    channels_t **res = NULL;
    char **uuids = get_array("channels:", filename);
    int alloc;

    for (alloc = 0; uuids[alloc] != NULL; alloc++);
    uuids = malloc(sizeof(channels_t *) * (alloc + 2));
    for (alloc = 0; uuids[alloc] != NULL; alloc++)
        res[alloc] = load_channel(uuids[alloc]);
    res[alloc + 1] = NULL;
    return res;
}

user_t **get_subscribers(char *filename)
{
    user_t **res = NULL;
    char **uuids = get_array("subscribers:", filename);
    int alloc;

    for (alloc = 0; uuids[alloc] != NULL; alloc++);
    uuids = malloc(sizeof(channels_t *) * (alloc + 2));
    for (alloc = 0; uuids[alloc] != NULL; alloc++)
        res[alloc] = load_user(uuids[alloc], -42, 1);
    res[alloc + 1] = NULL;
    return res;
}

teams_t *load_team(char *uuid)
{
    FILE *file;
    teams_t *team = malloc(sizeof(teams_t));
    char filename[49] = ".data/teams/";

    strcat(filename, uuid);
    if ((file = fopen(filename, "r"))) {
        team->uuid = uuid;
        team->name = get_field(filename, "name:");
        team->description = get_field(filename, "description:");
        team->channels = get_channels(filename);
        team->subscribers = get_subscribers(filename);
        fclose(file);
    } else
        printf("ERROR: Cannot load team #%s\n", uuid);
    return team;
}