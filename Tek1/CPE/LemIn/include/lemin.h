/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** lemin header file
*/

#ifndef LEMIN
#define LEMIN

#include <stdlib.h>

#include "my.h"

typedef struct s_coord coord_t;
typedef struct s_nodes nodes_t;
typedef struct s_links links_t;
typedef struct s_anthill anthill_t;

char **get_stdin(void);
int lemin(char** config);

int check_errors(char **file);
int check_nodes(nodes_t* nodes);

#endif
