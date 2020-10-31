/*
** EPITECH PROJECT, 2018
** find_all_path.c
** File description:
** .c
*/

#include "lemin.h"
#include "parsing.h"

nodes_t **find_connection_nodes(nodes_t *node, links_t *links)
{
    int i = 0;
    int nb_malloc = 0;
    nodes_t **to_return = NULL;

    for (links_t *tmp = links; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->node_1->name, node->name) == 0)
            nb_malloc++;
    }
    if (!(to_return = malloc(sizeof(nodes_t *) * (nb_malloc + 1))))
        return (NULL);
    for (links_t *tmp = links; i < nb_malloc; tmp = tmp->next) {
        if (my_strcmp(tmp->node_1->name, node->name) == 0) {
            to_return[i] = tmp->node_2;
            i++;
        }
    }
    to_return[nb_malloc] = NULL;
    return (to_return);
}

int get_all_connection(t_lemin *lemin)
{
    for (nodes_t *tmp = lemin->nodes; tmp != NULL; tmp = tmp->next) {
        if (!(tmp->connection = find_connection_nodes(tmp, lemin->links)))
            return (-1);
    }
    return (-1);
}
