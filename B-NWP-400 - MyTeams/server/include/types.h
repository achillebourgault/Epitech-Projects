/*
** EPITECH PROJECT, 2024
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Achille Bourgault
*/
#ifndef B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_TYPES_H
#define B_NWP_400_LIL_4_1_MYTEAMS_ACHILLE_BOURGAULT_TYPES_H

typedef struct messages_s {
    char *uuid;
    char *message;
    char *author_uuid;
    char *date_created;
} messages_t;

typedef struct private_discussion_s {
    char *uuid;
    char *author_uuid;
    char *guest_uuid;
    messages_t **messages;
} discussion_t;

typedef struct user_s {
    int cli_sock;
    char *uuid;
    char *name;
    int connected;
} user_t;

typedef struct threads_s {
    char *uuid;
    char *title;
    char *message;
    char *channel_uuid;
    char *date_created;
    messages_t **responses;
} threads_t;

typedef struct channels_s {
    char *uuid;
    char *name;
    char *team_uuid;
    char *description;
    threads_t **threads;
} channels_t;

typedef struct teams_s {
    char *uuid;
    char *name;
    char *description;
    channels_t **channels;
    user_t **subscribers;
} teams_t;

/* TEAM */
teams_t *create_team(char *name, char *uuid, char *description);
void add_new_subscriber(teams_t *team, char *user_uuid);
teams_t *load_team(char *uuid);
void save_team(teams_t *team);

/* USER */
user_t *create_user(char *name, int socket);
user_t *load_user(char *uuid, int cli_sock, int nb);
void save_user(user_t *user);

/* CHANNEL */
channels_t *create_channel(char *team_uuid, char *name, char *description);
channels_t *load_channel(char *uuid);
void save_channel(channels_t *user);

/* THREAD */
threads_t *create_thread(char *channel_uuid, char *name, char *content,
    char *user_uuid);
threads_t *load_thread(char *uuid);
void save_thread(threads_t *user);

/* MESSAGE */
messages_t *create_message(char *content, char *author_uuid,
    char *recipient_uuid);
messages_t *load_message(char *uuid);
void save_message(messages_t *message);
messages_t **get_responses(char *filename);

/* MP */
discussion_t *load_discussion(char *uuid);
discussion_t *create_discussion(char *author_uuid, char *guest_uuid,
    char *content_message);
void save_discussion(discussion_t *discussion);

#endif