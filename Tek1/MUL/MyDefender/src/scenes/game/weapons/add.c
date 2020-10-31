/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** weapons/add
*/

#include "my_defender.h"

sprite_texture_t* bind_weapons(int weapon)
{
    if (weapon == 1)
        return (init_spt("assets/img/turret1/test.png"));
    if (weapon == 2)
        return (init_spt("assets/img/turret2/turret2.png"));
    if (weapon == 3)
        return (init_spt("assets/img/turret3/turret3.png"));
    if (weapon == 4)
        return (init_spt("assets/img/plane.png"));
    return (NULL);
}

void new_weapons(window_t* current, sfVector2f position)
{
    game_t* game = current->scenes->game;

    game->weapons[game->weapons_count] = bind_weapons(current->click_action);
    sfSprite_setPosition(game->weapons[game->weapons_count]->sprite, position);
    game->weapons[game->weapons_count + 1] = NULL;
    game->weapons_count++;
}

void weapon_add(window_t* current)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(current->window);
    sfVector2f scope_pos;
    sfVector2f postion_dc;

    scope_pos.x = mouse_pos.x;
    scope_pos.y = mouse_pos.y;
    if (current->click_action != 4) {
        new_weapons(current, scope_pos);
    } else {
        postion_dc = scope_pos;
        postion_dc.x = 0;
        set_position_by_leader(current->scenes->game->delta_charlie, \
        postion_dc);
        current->scenes->game->delta_charlie->in_progress = true;
    }
    cursor_to_default(current);
    sfMouse_setPosition((sfVector2i){(scope_pos.x + 64), (scope_pos.y + 64)}, \
    (sfWindow*)current->window);
}

void set_value_weapons(game_t *game)
{
    game->weapons[game->weapons_count]->index = 0;
    game->weapons[game->weapons_count]->rect.top = 0;
    game->weapons[game->weapons_count]->rect.left = 0;
    game->weapons[game->weapons_count]->rect.width = 128;
    game->weapons[game->weapons_count]->rect.height = 128;
    game->weapons[game->weapons_count]->my_clock = sfClock_create();
}

void weapon_add_by_coord(window_t* current, sfVector2f position)
{
    game_t* game = current->scenes->game;
    sfVector2f pos = {64, 64};
    sfVector2f tmp = position;
    int angle = 0;

    tmp.x += 64;
    tmp.y += 64;
    game->weapons[game->weapons_count] = bind_weapons(current->click_action);
    sfSprite_setOrigin(game->weapons[game->weapons_count]->sprite, pos);
    sfSprite_setPosition(game->weapons[game->weapons_count]->sprite, tmp);
    game->weapons[game->weapons_count]->angle = 0;
    angle = (current->click_action == 2 || current->click_action == 3 ? 90 : 0);
    set_start_angle(game, tmp, angle);
    set_value_weapons(game);
    sfSprite_setTextureRect(game->weapons[game->weapons_count]->sprite, \
game->weapons[game->weapons_count]->rect);
    game->weapons[game->weapons_count + 1] = NULL;
    game->weapons_count++;
    cursor_to_default(current);
    sfMouse_setPosition((sfVector2i){(position.x + 64), (position.y + 64)}, \
    (sfWindow*)current->window);
}
