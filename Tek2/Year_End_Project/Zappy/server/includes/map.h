/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** map.h
*/

#ifndef ZAPPY_MAP_H
#define ZAPPY_MAP_H

#include <stdio.h>
#include <stdlib.h>

enum LINK_STATUS{LINK_OK, LINK_FAILED};
enum VIEW_DIRECTION{UP, LEFT, DOWN, RIGHT};

enum ENTITY_TYPE {PLAYER, EGG, RESOURCE};
enum RESOURCE_TYPE {FOOD, LINEMATE, DERAUMERE,
    SIBUR, MENDIANE, PHIRAS, THYSTAME, NONE};

typedef struct player_s player;
typedef struct egg_s egg;

typedef struct resource_s {
    enum RESOURCE_TYPE resource_type;
    char *resource_name;
    int amount;
    struct resource_s *prev;
    struct resource_s *next;
} resource_t;

typedef struct tile_entities_s {
    player *players;
    resource_t *resources;
    egg *eggs;
} tile_entities_t;

typedef struct map_tile_s {
    int pos_x; //Position X de la case sur la map
    int pos_y; //Position Y de la case sur la map
    struct map_tile_s *up; //Case au dessus
    struct map_tile_s *left; //Case à gauche
    struct map_tile_s *down; //Case du dessous
    struct map_tile_s *right; //Case à droite
    tile_entities_t *entities; //Objets sur la case(joueur, minerai, nourriture)
} map_tile_t;

typedef struct map_s {
    int width; //Largeur de la map
    int height; //Hauteur de la map
    map_tile_t *first_slot; //Cases d'objets
} map_t;

map_t *create_map(int width, int height);
int link_lines(map_tile_t *head1, map_tile_t *head2, int size);
int link_tiles(map_tile_t *tile1, map_tile_t *tile2, int direction);
map_tile_t *alloc_line(int x, int size);
map_tile_t *alloc_tile(int x, int y);
map_t *alloc_map(int width, int height);

char* get_resource_name(enum RESOURCE_TYPE type);
resource_t *create_resource(enum RESOURCE_TYPE resource_type, int amount);
char* tile_inventory_str(map_tile_t* tile);
int tile_inventory_str_len(map_tile_t* tile);
void loop_tile(map_t *map);
int get_tile_direction(map_tile_t* tile_a, map_tile_t* tile_b);

void free_map(map_t *map);

#endif //ZAPPY_MAP_H
