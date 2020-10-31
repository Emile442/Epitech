/*
** EPITECH PROJECT, 2018
** DRAW HEADER
** File description:
** HEADER
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "my.h"

typedef struct s_button {
    sfRectangleShape *rect;
    sfVector2f position;
    sfTexture* texture;
    sfTexture* txt_hover;
    sfTexture* txt_clicked;
    bool hidden;
    void (*callback)();
} button_t;

typedef struct s_sprite_texture {
    sfSprite *sprite;
    sfTexture *texture;
    int turret;
    sfIntRect rect;
    sfClock *my_clock;
    int side;
    sfVector2f position;
    float angle;
    int index;
} sprite_texture_t;

typedef struct s_enemy {
    sprite_texture_t* spt;
    float angle;
    float speed;
    int zone;
    int status;
    sfVector2f position;
    int life;
    sfClock* move;
} ennemy_t;

typedef struct s_home {
    sprite_texture_t* background;
    button_t* play;
    button_t* quit;
} home_t;

typedef struct s_pause {
    sprite_texture_t* background;
    button_t* resume;
    button_t* home;
    button_t* quit;
} pause_t;

typedef struct s_text {
    sfFont *font;
    sfText *text;
    sfClock* update;
    int value;
} text_t;

typedef struct s_info {
    text_t* score;
    text_t* money;
    text_t* level;
} info_t;

typedef struct s_hud {
    button_t* tower_1;
    button_t* tower_2;
    button_t* tower_3;
    button_t** towers_available;
    int available_slot;
    button_t* plane;
    button_t* pause;
    info_t* infos;
} hud_t;

typedef struct s_delta_charlie {
    sprite_texture_t* plane1;
    sprite_texture_t* plane2;
    sprite_texture_t* plane3;
    sfClock* fly;
    bool in_progress;
} delta_charlie_t;

typedef struct s_game {
    sprite_texture_t* background;
    hud_t* hud;
    ennemy_t** enemy;
    sprite_texture_t** weapons;
    delta_charlie_t* delta_charlie;
    int weapons_count;
    int enemy_count;
    sfClock* add_enemy;
    sfMusic* music;
    int level;
    int spawn;
} game_t;

typedef struct s_scene {
    home_t* home;
    game_t* game;
    pause_t* pause;
    void (*draw)();
} scene_t;

typedef struct s_framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct s_window {
    framebuffer_t *buffer;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    scene_t* scenes;
    sprite_texture_t* cursor;
    sprite_texture_t* default_cursor;
    int cursor_size;
    void (*click)();
    sfMusic* music_click;
    int click_action;
    bool exit;
} window_t;

window_t *init_frame(int width, int height, int bits);
int update_frame(window_t *current);
void destroy(window_t* current);

void home_destroy(home_t* home);
void game_destroy(game_t* game);

sfIntRect set_scale(int top, int left, int width, int height);
void show_help(void);

void button_init(button_t* button, sfVector2f position, sfVector2f size, \
char* path);
void button_destroy(button_t* button);
bool button_is_clicked(button_t* button, sfVector2i mouse);

sprite_texture_t* init_spt(char* path);
void destroy_spt(sprite_texture_t* spt);

home_t* home_init(void);
game_t* game_init(void);

hud_t* hud_init(void);
void hud_draw(window_t* current);
void hud_destroy(hud_t* hud);

button_t* init_tower_1_button(void);
void draw_tower_1_button(window_t* current);

button_t* init_tower_2_button(void);
void draw_tower_2_button(window_t* current);

button_t* init_tower_3_button(void);
void draw_tower_3_button(window_t* current);

button_t** init_towers_available_button(void);
void draw_towers_available_button(window_t* current);
void add_tower_available_button(hud_t* hud, sfVector2f position);

button_t* init_plane_button(void);
void draw_plane_button(window_t* current);

void move_left1(ennemy_t* enemy);
void move_left2(ennemy_t* enemy);
bool move_left3(ennemy_t* enemy);
void move_up1(ennemy_t* enemy);
void move_up2(ennemy_t* enemy);
void move_down(ennemy_t* enemy);
void ennemy_destroy(game_t* game);

sprite_texture_t** weapons_init(void);
void weapon_add(window_t* current);
void weapons_draw(window_t* current);
void weapon_add_by_coord(window_t* current, sfVector2f position);
void weapons_destroy(game_t* game);

void default_click(void);
void cursor_to_default(window_t* current);

ennemy_t** game_enemy_init(void);
void game_enemy_add(window_t* current);

void home_play_button_draw(window_t* current);
button_t* init_play_button(void);
void home_draw(window_t *current);

void game_enemy_draw(window_t* current);

void game_draw(window_t *current);

void home_quit_button_draw(window_t* current);
void home_quit_button_destroy(button_t* quit);
button_t* home_init_quit_button(void);

void pause_quit_button_draw(window_t* current);
void pause_quit_button_destroy(button_t* quit);
button_t* pause_init_quit_button(void);

void pause_resume_button_draw(window_t* current);
void pause_resume_button_destroy(button_t* resume);
button_t* pause_init_resume_button(void);

void pause_home_button_draw(window_t* current);
void pause_home_button_destroy(button_t* home);
button_t* pause_init_home_button(void);

void pause_destroy(pause_t* pause);
pause_t* pause_init(void);
void pause_draw(window_t *current);

button_t* init_pause_button(void);
void pause_button_draw(window_t* current);
void pause_button_destroy(button_t* pause);

info_t* init_info(void);
void draw_infos(window_t* current);
void destroy_infos(info_t* infos);

char *int_to_str(int nb);
char* str_with_num(char* const str, int const nbr);


delta_charlie_t* init_delta_charlie(void);
void draw_delta_charlie(window_t* current);
void set_position_by_leader(delta_charlie_t* dc, sfVector2f position);

void game_keyboard_event(window_t* current);

void delete_ennemy(game_t *game, int i);
int calc_dist(int ennemy_x, int ennemy_y, int weapon_x, int weapon_y);
int range_turret(sfVector2f pos_weapons, int dist, int j, game_t *game);
void set_start_angle(game_t *game, sfVector2f pos, int angle);
void destroy_one_ennemy(game_t *game, int i);

sfMusic* init_music(char* path);
void destroy_music(sfMusic* music);

void ennemy1(ennemy_t *enemy);
void ennemy2(ennemy_t *enemy);
void ennemy3(ennemy_t *enemy);
void boss_level(ennemy_t *enemy);

bool check_colision(sfSprite* sprite1, sfSprite* sprite2);

#endif
