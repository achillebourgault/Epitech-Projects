/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../../include/types.h"
#include "../../include/my_teams.h"

void save_thread(threads_t *thread)
{
    FILE *file;
    char filename[49] = ".data/threads/";

    strcat(filename, thread->uuid);
    file = fopen(filename, "w");
    if (file) {
        fprintf(file, "title:%s;\n", thread->title);
        fprintf(file, "message:%s;\n", thread->message);
        fprintf(file, "date_created:%s;\n", thread->date_created);
        fprintf(file, "responses:\n");
        if (thread->responses != NULL) {
            for (int x = 0; thread->responses[x] != NULL; x++) {
                fprintf(file, "\t%s;\n", thread->responses[x]->uuid);
            }
        }
        fclose(file);
    }
}

threads_t *create_thread(char *channel_uuid, char *name, char *content,
    char *user_uuid)
{
    threads_t *thread = malloc(sizeof(threads_t));

    thread->uuid = generate_uuid();
    thread->title = strdup(name);
    thread->message = strdup(content);
    thread->date_created = give_time();
    thread->channel_uuid = strdup(channel_uuid);
    thread->responses = NULL;
    server_event_thread_created(channel_uuid, thread->uuid, user_uuid,
        thread->title, thread->message);
    save_thread(thread);
    return thread;
}

threads_t *load_thread(char *uuid)
{
    FILE *file;
    threads_t *thread = malloc(sizeof(threads_t));
    char filename[49] = ".data/threads/";

    strcat(filename, uuid);
    if ((file = fopen(filename, "r"))) {
        thread->uuid = uuid;
        thread->title = get_field(filename, "title:");
        thread->message = get_field(filename, "message:");
        thread->date_created = get_field(filename, "date_created:");
        thread->responses = get_responses(filename);
        fclose(file);
    } else
        printf("ERROR: Cannot load thread #%s\n", uuid);
    return thread;
}

messages_t **get_responses(char *filename)
{
    messages_t **res = NULL;
    char **uuids = get_array("responses:", filename);
    int alloc;

    for (alloc = 0; uuids[alloc] != NULL; alloc++);
    uuids = malloc(sizeof(channels_t *) * (alloc + 2));
    for (alloc = 0; uuids[alloc] != NULL; alloc++)
        res[alloc] = load_message(uuids[alloc]);
    res[alloc + 1] = NULL;
    return res;
}