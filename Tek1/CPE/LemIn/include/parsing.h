/*
** EPITECH PROJECT, 2019
** parsing
** File description:
** parsing related functions and structures
*/

#ifndef PARSING
#define PARSING

#include <stdbool.h>

typedef struct s_coord {
    int x;
    int y;
} coord_t;

typedef struct s_nodes {
    int x;
    int y;
    char *name;
    bool available;
    int node_type;
    int distance;
    struct s_nodes *next;
    struct s_nodes **connection;
} nodes_t;

typedef struct s_links {
    nodes_t *node_1;
    nodes_t *node_2;
    struct s_links *next;
} links_t;

typedef struct s_anthill {
    int ants;
    links_t *links;
    nodes_t *nodes;
} anthill_t;

int is_comment(char *line);
nodes_t *create_node(coord_t coord, char *name, int type);
int add_node(coord_t coord, char *name, int type, nodes_t *nodes);
void destroy_nodes(nodes_t *nodes);
int count_words(char *str);
links_t *create_link(nodes_t *node_1, nodes_t *node_2);
int add_link(nodes_t *node_1, nodes_t *node_2, links_t *links);
void destroy_links(links_t *links);
anthill_t *create_anthill(void);
void destroy_anthill(anthill_t *anthill);
int is_valid_node(char *line);
coord_t get_coord(char const *line);
char *dup_word(char const *str);
void find_nodes(nodes_t **node_1, nodes_t **node_2,
char *line, nodes_t *nodes);
bool is_line_a_link(char *line);
int get_ant_number(void);
void get_next_links(nodes_t *nodes, links_t *links);
links_t *get_next_link(nodes_t *nodes, char *first);
void print_link_details(links_t *link);
nodes_t *get_next_node(char **next);
void print_room_details(nodes_t *node);
int get_next_rooms(nodes_t *nodes, char **first_line);
anthill_t *get_anthill(void);

#endif
