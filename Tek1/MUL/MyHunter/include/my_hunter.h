/*
** EPITECH PROJECT, 2018
** DRAW HEADER
** File description:
** HEADER
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#ifndef MY_HUNTER_H
#define MY_HUNTER_H

typedef struct s_framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct s_bird {
    int x;
    int y;
    sfSprite *sprite;
    sfTexture *texture;
    sfMusic *fire;
    sfIntRect step[4];
    int skinStep;
} bird_t;

typedef struct s_scoreboard {
    sfFont *font;
    sfText *text;
} scoreboard_t;

typedef struct s_sprite_texture {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_texture_t;

typedef struct s_lifes {
    sprite_texture_t *one;
    sprite_texture_t *two;
    sprite_texture_t *three;
} lifes_t;

typedef struct s_window {
    framebuffer_t *buffer;
    bird_t *bird;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite;
    sfTexture *texture;
    int lives;
    int score;
    int status;
    sprite_texture_t *background;
    sprite_texture_t *play_button;
    sprite_texture_t *scope;
    scoreboard_t *scoreboard;
    sprite_texture_t *stop_button;
    sprite_texture_t *restart_button;
    sprite_texture_t *exit_button;
    lifes_t *life;
} window_t;

#endif

sfIntRect set_scale(int top, int left, int width, int height);
bool is_in_range(int a, int b, int value);
void set_sprite_bird(window_t *current);
void bird_anim(sfClock *anim_clock, window_t *current);
void bird_dead_listener(window_t *current);
void reset_bird(window_t *current);
void bird_init(window_t *current);
void show_help(void);
void event_listener(window_t *current);
void set_scope_bg_button(window_t *current);
void game_lister(window_t *current);
char *int_to_str(int nb);
void init_scoreboard(window_t *current);
void life_display(window_t *current);
void init_lifes(window_t *current);
void button_display(window_t *current);
void init_button(window_t *current);