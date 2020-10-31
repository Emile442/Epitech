/*
** EPITECH PROJECT, 2019
** create
** File description:
** links
*/

#include "parsing.h"
#include "my.h"
#include <stdlib.h>

links_t *get_next_link(nodes_t *nodes, char *first)
{
    char *line = first ? first : get_next_line(0);
    int comment;
    nodes_t *node_1 = NULL;
    nodes_t *node_2 = NULL;

    if (!line)
        return (NULL);
    while ((comment = is_comment(line)) == 1) {
        free(line);
        if (!(line = get_next_line(0)))
            return (NULL);
    }
    if (comment || !line[0] || !is_line_a_link(line))
        return (NULL);
    find_nodes(&node_1, &node_2, line, nodes);
    if (!node_1 || !node_2)
        return (NULL);
    free(line);
    return (create_link(node_1, node_2));
}

void print_link_details(links_t *link)
{
    my_printf("%s-%s\n", link->node_1->name, link->node_2->name);
}

void get_next_links(nodes_t *nodes, links_t *links)
{
    links_t *next = get_next_link(nodes, NULL);

    while (next) {
        print_link_details(next);
        links->next = next;
        links = links->next;
        next = get_next_link(nodes, NULL);
    }
}

