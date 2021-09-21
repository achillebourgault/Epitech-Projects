/*
** EPITECH PROJECT, 2021
** B_NWP_400_LIL_4_1_myteams_achille_bourgault
** File description:
** Created by Frédéric LAWECKI--WALKOWIAK
*/

#include <stdlib.h>
#include <uuid/uuid.h>

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid;

    uuid_generate_random(binuuid);
    uuid = malloc(37);
    uuid_unparse_lower(binuuid, uuid);
    return uuid;
}