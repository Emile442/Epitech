/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** weapons/delta_charlie
*/

#include "my_defender.h"

void set_position_by_leader(delta_charlie_t* dc, sfVector2f position)
{
    dc->plane1->position = position;
    sfSprite_setPosition(dc->plane1->sprite, dc->plane1->position);
    dc->plane2->position = position;
    dc->plane2->position.y -= 100;
    dc->plane2->position.x -= 100;
    sfSprite_setPosition(dc->plane2->sprite, dc->plane2->position);
    dc->plane3->position = position;
    dc->plane3->position.y += 100;
    dc->plane3->position.x -= 100;
    sfSprite_setPosition(dc->plane3->sprite, dc->plane3->position);
}

void update_delta_charlie(window_t* current)
{
    delta_charlie_t* dc = current->scenes->game->delta_charlie;

    if (sfClock_getElapsedTime(dc->fly).microseconds / 100 > 100) {
        sfClock_restart(dc->fly);
        dc->plane1->position.x += 10;
        set_position_by_leader(dc, dc->plane1->position);
        if (dc->plane1->position.x > 1920) {
            dc->in_progress = false;
            dc->plane1->position.x = 0;
        }
    }
}

void draw_delta_charlie(window_t* current)
{
    delta_charlie_t* dc = current->scenes->game->delta_charlie;
    ennemy_t** enemy = current->scenes->game->enemy;

    sfRenderWindow_drawSprite(current->window, dc->plane1->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, dc->plane2->sprite, NULL);
    sfRenderWindow_drawSprite(current->window, dc->plane3->sprite, NULL);
    for (int i = 0; i != current->scenes->game->enemy_count; i++) {
        if (check_colision(dc->plane1->sprite, enemy[i]->spt->sprite) ||
        check_colision(dc->plane2->sprite, enemy[i]->spt->sprite) ||
        check_colision(dc->plane3->sprite, enemy[i]->spt->sprite)) {
            enemy[i]->life -= 90;
        }
    }
    update_delta_charlie(current);
}

delta_charlie_t* init_delta_charlie(void)
{
    delta_charlie_t* dc = malloc(sizeof(delta_charlie_t));
    sfVector2f position = {0, 0};

    dc->plane1 = init_spt("assets/img/plane.png");
    dc->plane2 = init_spt("assets/img/plane.png");
    dc->plane3 = init_spt("assets/img/plane.png");
    dc->fly = sfClock_create();
    dc->in_progress = false;
    set_position_by_leader(dc, position);
    return (dc);
}
