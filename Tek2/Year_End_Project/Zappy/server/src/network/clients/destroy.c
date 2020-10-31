/*
** EPITECH PROJECT, 2020
** zappy
** File description:
** Clients Destroy
*/

#include "zappy_server.h"

void clients_destroy(client_t* clients)
{
    client_t* tmp = NULL;

    while (tmp != NULL) {
        tmp = clients;
        clients = clients->next;
        free(tmp);
    }
}
