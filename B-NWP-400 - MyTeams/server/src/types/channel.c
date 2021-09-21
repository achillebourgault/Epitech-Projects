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
#include "../../include/types.h"

void save_channel(channels_t *channel)
{
    FILE *file;
    char filename[49] = ".data/channels/";

    strcat(filename, channel->uuid);
    if ((file = fopen(filename, "w"))) {
        fprintf(file, "name:%s;\n", channel->name);
        fprintf(file, "description:%s;\n", channel->description);
        fprintf(file, "teamId:%s;\n", channel->team_uuid);
        fprintf(file, "threads:%s;\n", "TODO");
        fclose(file);
    }
}

channels_t *create_channel(char *team_uuid, char *name, char *description)
{
    channels_t *channel = malloc(sizeof(channels_t));

    channel->uuid = generate_uuid();
    channel->team_uuid = strdup(team_uuid);
    channel->name = strdup(name);
    channel->description = strdup(description);
    save_channel(channel);
    server_event_channel_created(channel->team_uuid, channel->uuid,
        channel->name);
    return channel;
}

channels_t *load_channel(char *uuid)
{
    FILE *file;
    channels_t *channel = malloc(sizeof(channels_t));
    char filename[49] = ".data/channels/";

    strcat(filename, uuid);
    if ((file = fopen(filename, "r"))) {
        channel->uuid = strdup(uuid);
        channel->team_uuid = get_field(filename, "teamId:");
        channel->name = get_field(filename, "name:");
        channel->description = get_field(filename, "description:");
        fclose(file);
    } else
        printf("ERROR: Cannot load channel #%s\n", uuid);
    return channel;
}