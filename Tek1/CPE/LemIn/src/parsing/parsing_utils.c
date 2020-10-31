/*
** EPITECH PROJECT, 2019
** create_node_from_file.c
** File description:
** creates a node from file content
*/

#include "parsing.h"
#include "my.h"
#include <stdlib.h>

char *dup_word(char const *str)
{
    int len = 0;
    char *word;

    while (str[len] != '\0' && str[len] != ' ' && str[len] != '\t')
        len++;
    if (!(word = malloc(sizeof(char) * len + 1)))
        return (NULL);
    word[len] = 0;
    for (int i = 0; i < len; i++)
        word[i] = str[i];
    return (word);
}

coord_t get_coord(char const *line)
{
    int i = 0;
    coord_t coord;

    while (line[i] == ' ')
        i++;
    while (line[i] != ' ')
        i++;
    while (line[i] == ' ')
        i++;
    coord.x = my_get_nbr(&line[i]);
    while (line[i] != ' ')
        i++;
    while (line[i] == ' ')
        i++;
    coord.y = my_get_nbr(&line[i]);
    return (coord);
}

bool is_line_a_link(char *line)
{
    int dash = 0;
    int j = 0;

    if (count_words(line) != 1)
        return (false);
    for (int i = 0; line[i]; i++)
        if (line[i] == '-')
            dash++;
    if (dash != 1)
        return (false);
    while (line[j] != '-')
        j++;
    if (j == 0 || !line[j] || !line[j + 1])
        return (false);
    return (true);
}

void find_nodes(nodes_t **node_1, nodes_t **node_2,
char *line, nodes_t *nodes)
{
    int i;

    for (i = 0; line[i] != '-'; i++);
    line[i++] = 0;
    (*node_1) = nodes;
    while ((*node_1) && !my_strcmp(line, (*node_1)->name))
        (*node_1) = (*node_1)->next;
    for (nodes_t *tmp = (*node_1)?(*node_1)->next:0; tmp; tmp = tmp->next)
        if (my_strcmp((*node_1)->name, tmp->name)) {
            (*node_1) = NULL;
            break;
        }
    (*node_2) = nodes;
    while ((*node_2) && !my_strcmp(&line[i], (*node_2)->name))
        (*node_2) = (*node_2)->next;
    for (nodes_t *tmp = (*node_2) ? (*node_2)->next:0; tmp; tmp = tmp->next)
        if (my_strcmp((*node_2)->name, tmp->name)) {
            (*node_2) = NULL;
            break;
        }
    line[--i] = '-';
}
