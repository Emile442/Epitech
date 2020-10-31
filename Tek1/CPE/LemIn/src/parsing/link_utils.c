/*
** EPITECH PROJECT, 2019
** links utils
** File description:
** utils for links
*/

#include "parsing.h"
#include <stdlib.h>

links_t *create_link(nodes_t *node_1, nodes_t *node_2)
{
    links_t *link = malloc(sizeof(links_t));

    if (!link)
        return (NULL);
    link->next = NULL;
    link->node_1 = node_1;
    link->node_2 = node_2;
    return (link);
}

int add_link(nodes_t *node_1, nodes_t *node_2, links_t *links)
{
    while (links->next)
        links = links->next;
    if (!(links->next = create_link(node_1, node_2)))
        return (0);
    return (1);
}

void destroy_links(links_t *links)
{
    if (links->next)
        destroy_links(links->next);
    free(links);
}
