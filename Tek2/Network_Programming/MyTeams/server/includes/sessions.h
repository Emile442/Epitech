/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** sessions.h
*/

#ifndef MYTEAMS_SERVER_SESSIONS_H
#define MYTEAMS_SERVER_SESSIONS_H

typedef struct user_s {
    char* uuid;
    char* username;
    int socket;
    struct user_s* next;
} user_t;

typedef struct sessions_s {
    user_t* connected;
    user_t* all;
} sessions_t;

user_t* user_get_by_uuid(user_t *list, const char* uuid);
user_t* user_create(const char* username, int socket);
user_t* user_found_by_name(user_t *list, const char* username);
void users_push(user_t** list, user_t* user);
void users_pull(user_t **list);
void user_remove_by_uuid(user_t **list, const char* uuid);
char* get_user_str(user_t* user, int status);
user_t* user_copy(user_t* user);
user_t* user_found_by_uuid(user_t *list, const char* uuid);


#endif //MYTEAMS_SERVER_SESSIONS_H
