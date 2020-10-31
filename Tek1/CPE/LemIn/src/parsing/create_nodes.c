/*
** EPITECH PROJECT, 2019
** create
** File description:
** nodes
*/

#include "parsing.h"
#include <stdlib.h>
#include "my.h"

nodes_t *get_node_from_line(char *line, int type, char **next)
{
    char *name;
    coord_t coord;

    if (!is_valid_node(line)) {
        *next = line;
        return (NULL);
    }
    name = dup_word(line);
    coord = get_coord(line);
    if (!name)
        return (NULL);
    free(line);
    return (create_node(coord, name, type));
}

nodes_t *get_next_node(char **next)
{
    char *line = get_next_line(0);
    int comment;
    int type = 1;

    if (!line)
        return (NULL);
    while ((comment = is_comment(line)) == 1) {
        free(line);
        if (!(line = get_next_line(0)))
            return (NULL);
    }
    comment == 2 ? (type = 2) : 0;
    comment == 3 ? (type = 0) : 0;
    if (comment == 2 || comment == 3) {
        free(line);
        if (!(line=get_next_line(0))||is_comment(line))
            return (NULL);
    }
    return (get_node_from_line(line, type, next));
}

void print_room_details(nodes_t *node)
{
    if (node->node_type == 0)
        my_printf("##start\n");
    else if (node->node_type == 2)
        my_printf("##end\n");
    my_printf("%s %d %d\n", node->name, node->x, node->y);
}

int check_other_nodes(nodes_t *list, nodes_t *current)
{
    while (list) {
        if (list == current)
            continue;
        if (my_strcmp(list->name, current->name))
            return (-1);
        if (list->x == current->x && list->y == current->y)
            return (-1);
        list = list->next;
    }
    return (0);
}

int get_next_rooms(nodes_t *nodes, char **first_line)
{
    nodes_t *next = get_next_node(first_line);
    nodes_t *tmp = nodes;
    int start = !nodes->node_type ? 1 : 0;
    int end = nodes->node_type == 2 ? 1 : 0;

    while (next) {
        if (check_other_nodes(nodes, next) == -1)
            return (-1);
        (tmp->next = next, tmp = tmp->next);
        if (next->node_type == 0)
            start++;
        else if (next->node_type == 2)
            end++;
        if (end > 1 || start > 1)
            return (-1);
        print_room_details(tmp);
        next = get_next_node(first_line);
    }
    if (!start || !end)
        return (-1);
    return (0);
}
