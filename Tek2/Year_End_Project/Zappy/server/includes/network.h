/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Server Network
*/

#ifndef MY_NETWORK_H_
#define MY_NETWORK_H_

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

struct player_s;

typedef struct client_s {
    int socket;
    char* uuid;
    struct player_s *player;
    struct client_s* next;
} client_t;

typedef struct network_s {
    int socket;
    struct sockaddr_in socket_params;
    int max_clients;
    client_t* clients;
    struct player_s *players;
} network_t;


network_t* network_create(int port);
int network_start(network_t* network);
void network_destroy(network_t* network);

void socket_init(struct sockaddr_in *address, int port);
int socket_start(network_t* network);
int socket_bind(network_t* network);
int socket_listen(network_t* network);

void clients_init(network_t* network);
bool clients_new(network_t* network, fd_set readfds);
void clients_destroy(client_t* clients);

void client_push(client_t **list, int socket);
client_t* client_found_by_uuid(client_t *list, const char* uuid);
void client_remove(client_t **list, client_t *query);
int client_size(client_t* clients);

#endif /* !MY_NETWORK_H_ */
