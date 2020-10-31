/*
** EPITECH PROJECT, 2019
** node utils
** File description:
** node utils
*/

#include "parsing.h"
#include <stdlib.h>

nodes_t *create_node(coord_t coord, char *name, int type)
{
    nodes_t *node = malloc(sizeof(nodes_t));

    if (!node)
        return (NULL);
    node->name = name;
    node->x = coord.x;
    node->y = coord.y;
    node->node_type = type;
    node->next = NULL;
    node->available = true;
    node->distance = type ? 2147483647 : 0;
    return (node);
}

int add_node(coord_t coord, char *name, int type, nodes_t *nodes)
{
    while (nodes->next)
        nodes = nodes->next;
    if (!(nodes->next = create_node(coord, name, type)))
        return (0);
    return (1);
}

void destroy_nodes(nodes_t *nodes)
{
    if (nodes->next)
        destroy_nodes(nodes->next);
    free(nodes->name);
    free(nodes);
}
