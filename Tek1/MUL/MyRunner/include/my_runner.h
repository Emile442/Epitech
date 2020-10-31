/*
** EPITECH PROJECT, 2018
** DRAW HEADER
** File description:
** HEADER
*/

#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MY_RUNNER_H
#define MY_RUNNER_H

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct sprite_texture_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
} sprite_texture_t;

typedef struct parallax_s {
    sprite_texture_t *background;
    sprite_texture_t *midground;
    sprite_texture_t *midground_copy;
    sprite_texture_t *foreground;
    sprite_texture_t *foreground_copy;
    sprite_texture_t *ground;
    sprite_texture_t *ground_copy;
} parallax_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect run_s[10];
    sfIntRect jump_s[15];
    sfVector2f jump_p[15];
    sfMusic *jump_music;
    sfVector2f pos;
    int spriteStep;
    bool jump;
} player_t;

typedef struct s_scoreboard {
    sprite_texture_t *score_img;
    sfFont *font;
    sfText *text;
    int value;
} scoreboard_t;

typedef struct clock_list_s {
    sfClock *player;
    sfClock *pr_ground;
    sfClock *pr_foreground;
    sfClock *pr_midground;
    sfClock *obstacle;
    sfClock *score;
    sfClock *pumkin;
    sfClock *map;
} clock_list_t;

typedef struct map_s {
    int value;
    sprite_texture_t* entity;
    struct map_s *next;
} map_t;

typedef struct window_s {
    framebuffer_t *buffer;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfMusic *music;
    sfEvent event;
    parallax_t *parallax;
    sprite_texture_t *box;
    player_t *player;
    scoreboard_t *scoreboard;
    clock_list_t *clock_list;
    map_t *map;
    map_t *waiting;
    map_t *actual;
    int lives;
    bool error;
} window_t;

sfIntRect set_scale(int top, int left, int width, int height);
void show_help(void);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
window_t *init_frame(int width, int height, int bits, char* path);
int update_frame(window_t *current);
void event_listener(window_t *current);
void set_player_run_sprite(window_t *current);
void set_player_jump_sprite(window_t *current);
void set_player(window_t *current);
void init_parallax(window_t *current);
void player_anim(window_t *current);
void new_box(window_t *current);
void player_listener(window_t *current);
void init_sprite(sprite_texture_t *st, char* filepath);
void parallax_draw(window_t *current);
void init_clock(window_t *current);
void game_anim(window_t *current);
void parallax_anim(clock_list_t *clock, window_t *current);
void item_anim(sfClock *clock_i, sprite_texture_t *actual, \
sprite_texture_t *copy, int fps);
void player_draw(window_t *current);
void box_colision(window_t *current);
char *int_to_str(int nb);
void score_init(window_t *current);
void score_draw(window_t *current);
void score_update(window_t *current);
bool map_init(window_t *current, char* filepath);
int count_list(map_t **list);
void reverse_list(map_t **list);
void push_list(map_t **list, int value);
void pull_list(map_t **list);
int next_list(map_t **list);
void box_waiting(window_t *current);
void score_destroy(window_t *current);
void game_destroy(window_t *current);
void box_draw(window_t *current);
void box_anim(window_t *current);
#endif
