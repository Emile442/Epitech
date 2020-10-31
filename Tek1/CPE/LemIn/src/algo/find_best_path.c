/*
** EPITECH PROJECT, 2019
** CPE_lemin_2018
** File description:
** find_best_path
*/

#include "lemin.h"
#include "parsing.h"
#include "path.h"

path_t* init_path(void)
{
    path_t* path = malloc(sizeof(path_t));

    path->node = NULL;
    path->jump = -1;
    path->end = false;
    return (path);
}

path_t* find_end(nodes_t* master, path_t* next)
{
    nodes_t* scope = next == NULL ? master : next->node;
    path_t* tmp = next == NULL ? init_path() : next;
    path_t* actual;

    tmp->jump++;
    for (int i = 0; scope->connection[i]; i++) {
        actual = init_path();
        actual->node = scope->connection[i];
        if (actual->node->node_type != 2)
            tmp =find_end(master, tmp);
    }
    return (tmp->end ? tmp : find_end(master, tmp));
}

nodes_t* find_best_path(nodes_t* nodes)
{
    path_t* tmp = init_path();
    path_t* actual = init_path();

    if (nodes->node_type == 2)
        return (nodes);
    for (int i = 0; nodes->connection[i]; i++) {
        if (!nodes->connection[i]->available)
            continue;
        if (nodes->connection[i]->node_type == 2)
            return (nodes->connection[i]);
        actual = find_end(nodes->connection[i], NULL);
        if (tmp->jump == -1 || tmp->jump > actual->jump)
            tmp = actual;
    }
    free(actual);
    return (tmp->node);
}
