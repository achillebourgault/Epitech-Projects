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

void save_message(messages_t *message)
{
    FILE *file;
    char filename[49] = ".data/messages/";
    strcat(filename, message->uuid);
    if ((file = fopen(filename, "w"))) {
        fprintf(file, "message:%s;\n", message->message);
        fprintf(file, "authorId:%s;\n", message->author_uuid);
        fprintf(file, "date_created:%s;\n", message->date_created);
        fclose(file);
    }
}

messages_t *create_message(char *content, char *author_uuid,
    char *recipient_uuid)
{
    messages_t *message = malloc(sizeof(messages_t));
    message->uuid = generate_uuid();
    message->author_uuid = strdup(author_uuid);
    message->message = strdup(content);
    message->date_created = give_time();
    save_message(message);
    return message;
}

messages_t *load_message(char *uuid)
{
    FILE *file;
    messages_t *message = malloc(sizeof(messages_t));
    char filename[49] = ".data/messages/";
    strcat(filename, uuid);
    if ((file = fopen(filename, "r"))) {
        message->uuid = strdup(uuid);
        message->message = get_field(filename, "message:");
        message->author_uuid = get_field(filename, "authorId:");
        message->date_created = get_field(filename, "date_created:");
        fclose(file);
    } else
        printf("ERROR: Cannot load message #%s\n", uuid);
    return message;
}

discussion_t *get_private_message_by_uuid(char *uuid_send, char *guest_uuid,
    discussion_t **private_discussion)
{
    if (private_discussion == NULL)
        return (NULL);
    for (int i = 0; private_discussion[i] != NULL; i++)
        if ((strcmp(private_discussion[i]->author_uuid, uuid_send) == 0 &&
            strcmp(private_discussion[i]->guest_uuid, guest_uuid) == 0))
            return (private_discussion[i]);
    return (NULL);
}