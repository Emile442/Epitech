/*
** EPITECH PROJECT, 2019
** anthill utils
** File description:
** anthill utils
*/

#include "parsing.h"
#include "my.h"
#include <stdlib.h>

int get_ant_number(void)
{
    char *line = get_next_line(0);
    int comment;
    int to_return;

    if (!line)
        return (-1);
    comment = is_comment(line);
    while (comment == 1) {
        free(line);
        if (!(line = get_next_line(0)))
            return (-1);
        comment = is_comment(line);
    }
    if (comment != 0 || !is_num(line))
        return (-1);
    if (!line[0])
        return (-1);
    to_return = my_get_nbr(line);
    free(line);
    return (to_return);
}

anthill_t *create_anthill(void)
{
    anthill_t *anthill = malloc(sizeof(anthill_t));

    if (!anthill)
        return (NULL);
    anthill->ants = -1;
    anthill->links = NULL;
    anthill->nodes = NULL;
    return (anthill);
}

void destroy_anthill(anthill_t *anthill)
{
    destroy_links(anthill->links);
    destroy_nodes(anthill->nodes);
    free(anthill);
}

anthill_t *get_anthill(void)
{
    anthill_t *anthill = create_anthill();
    char *line = NULL;

    if (!anthill)
        return (NULL);
    if ((anthill->ants = get_ant_number()) == -1)
        return (NULL);
    my_printf("#number_of_ants\n%d\n", anthill->ants);
    if (!(anthill->nodes = get_next_node(&line)))
        return (NULL);
    my_printf("#rooms\n");
    print_room_details(anthill->nodes);
    if (get_next_rooms(anthill->nodes, &line) == -1)
        return (NULL);
    if (!(anthill->links = get_next_link(anthill->nodes, line)))
        return (NULL);
    my_printf("#tunnels\n");
    print_link_details(anthill->links);
    get_next_links(anthill->nodes, anthill->links);
    return (anthill);
}
