/*
** EPITECH PROJECT, 2018
** bird_hunter
** File description:
** Hunter Bird
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Audio.h>

#include "my_hunter.h"

void set_sprite_bird(window_t *current)
{
    int width = 600;
    int height = 150;

    current->bird->step[0] = set_scale(0, 0, width / 4, height);
    current->bird->step[1] = set_scale(0, 150, width / 4, height);
    current->bird->step[2] = set_scale(0, 300, width / 4, height);
    current->bird->step[3] = set_scale(0, 450, width / 4, height);
    current->bird->skinStep = 0;
}

void reset_bird(window_t *current)
{
    int randY = 0;
    sfVector2f tmp;

    randY = rand() % 850;
    tmp.x = 0;
    tmp.y = randY;
    current->bird->x = 0;
    current->bird->y = randY;
    sfSprite_setPosition(current->bird->sprite, tmp);
}

void bird_anim(sfClock *anim_clock, window_t *current)
{
    int speed = 60 + (15 * current->score);
    sfVector2f tmp;

    sfClock_restart(anim_clock);
    current->bird->skinStep++;
    sfSprite_setTextureRect(current->bird->sprite, \
    current->bird->step[current->bird->skinStep]);
    if (current->bird->skinStep == 3)
        current->bird->skinStep = -1;
    tmp.x = speed;
    tmp.y = 0;
    current->bird->x += speed;
    sfSprite_move(current->bird->sprite, tmp);
    if (current->bird->x >= 1920)
        reset_bird(current);
}

void bird_dead_listener(window_t *current)
{
    sfVector2i mouseP;
    int rgX = 0;
    int rgY = 0;

    if (current->event.type == sfEvtMouseButtonPressed \
    && current->status == 1) {
        mouseP = sfMouse_getPositionRenderWindow(current->window);
        rgX = is_in_range(current->bird->x, current->bird->x + 150, mouseP.x);
        rgY = is_in_range(current->bird->y, current->bird->y + 150, mouseP.y);
        sfMusic_stop(current->bird->fire);
        sfMusic_play(current->bird->fire);
        if (rgX && rgY) {
            reset_bird(current);
            current->score++;
            sfText_setString(current->scoreboard->text, \
            int_to_str(current->score));
        } else
            current->lives--;
    }
}

void bird_init(window_t *current)
{
    set_sprite_bird(current);
    current->bird->texture = sfTexture_createFromFile("img/bird.png", NULL);
    current->bird->x = 0;
    current->bird->y = 0;
    current->bird->fire = sfMusic_createFromFile("music/fire.ogg");
    current->bird->sprite = sfSprite_create();
    sfSprite_setTexture(current->bird->sprite, current->bird->texture, sfTrue);
    sfSprite_setTextureRect(current->bird->sprite, current->bird->step[0]);
}