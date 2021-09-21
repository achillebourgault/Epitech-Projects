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

void save_discussion(discussion_t *discussion)
{
    FILE *file;
    char filename[49] = ".data/mp/";

    strcat(filename, discussion->uuid);
    file = fopen(filename, "w");
    if (file) {
        fprintf(file, "authorId:%s;\n", discussion->author_uuid);
        fprintf(file, "guestId:%s;\n", discussion->guest_uuid);
        fprintf(file, "messages:\n");
        for (int x = 0; discussion->messages[x] != NULL; x++)
            fprintf(file, "\t%s;\n", discussion->messages[x]->uuid);
        fclose(file);
    }
}

discussion_t *create_discussion(
    char *author_uuid, char *guest_uuid,
    char *content_message
)
{
    discussion_t *discussion = malloc(sizeof(discussion_t));

    discussion->uuid = generate_uuid();
    discussion->author_uuid = strdup(author_uuid);
    discussion->guest_uuid = strdup(guest_uuid);
    discussion->messages = malloc(sizeof(messages_t *) * (2));
    discussion->messages[0] = create_message(content_message, author_uuid,
        guest_uuid);
    discussion->messages[1] = NULL;
    save_discussion(discussion);
    return discussion;
}

messages_t **get_messages(char *filename)
{
    messages_t **res = NULL;
    char **uuids = get_array("messages:", filename);
    int alloc;

    for (alloc = 0; uuids[alloc] != NULL; alloc++);
    res = malloc(sizeof(messages_t *) * (alloc + 1));
    for (alloc = 0; uuids[alloc] != NULL; alloc++)
        res[alloc] = load_message(uuids[alloc]);
    res[alloc] = NULL;
    if (res[0] != NULL)
        return res;
    return NULL;
}

discussion_t *load_discussion(char *uuid)
{
    FILE *file;
    discussion_t *discussion = malloc(sizeof(discussion_t));
    char filename[49] = ".data/mp/";

    strcat(filename, uuid);
    if ((file = fopen(filename, "r"))) {
        discussion->uuid = strdup(uuid);
        discussion->author_uuid = get_field(filename, "authorId:");
        discussion->guest_uuid = get_field(filename, "guestId:");
        discussion->messages = get_messages(filename);
        fclose(file);
    } else
        printf("ERROR: Cannot load discussion #%s\n", uuid);
    return discussion;
}