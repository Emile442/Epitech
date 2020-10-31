/*
** EPITECH PROJECT, 2020
** myteams_server
** File description:
** messages.h
*/

#ifndef MYTEAMS_SERVER_PRIVATE_MESSAGES_H
#define MYTEAMS_SERVER_PRIVATE_MESSAGES_H

typedef struct message_s {
    char* body;
    char* from;
    time_t created_at;
    struct message_s* next;
} message_t;

typedef struct conversation_s {
    char* uuid1;
    char* uuid2;
    message_t* messages;
    struct conversation_s* next;
} conversation_t;

void conversations_push(conversation_t** list, conversation_t* conv);
conversation_t* conversations_create(const char* uuid1, const char* uuid2);
conversation_t* conv_get_by_uuid(conversation_t *list, const char* uuid1, \
const char* uuid2);
void conversations_remove_by_uuid(conversation_t **list, const char* uuid1, \
const char* uuid2);
conversation_t* conversations_found_by_uuid(conversation_t *list, \
const char* uuid1, const char* uuid2);

void messages_push(message_t ** list, message_t* msg);
message_t* messages_create(const char* from, const char* body);
void messages_print(message_t **list);
void conversations_print(conversation_t **list);
char* messages_str(const char* uuid, time_t created_at, const char* body);


#endif //MYTEAMS_SERVER_PRIVATE_MESSAGES_H
