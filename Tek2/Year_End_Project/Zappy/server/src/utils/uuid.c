/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** uuid
*/

#include "zappy_server.h"
#include <uuid/uuid.h>

char* generate_uuid(void)
{
    char *rt = malloc(37);
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, rt);
    uuid_unparse(binuuid, rt);
    return (rt);
}
