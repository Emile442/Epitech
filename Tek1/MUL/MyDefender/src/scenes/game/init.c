/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** game/init
*/

#include "my_defender.h"

game_t* game_init(void)
{
    game_t* game = malloc(sizeof(game_t));

    game->background = init_spt("assets/img/game_background.jpg");
    game->enemy = game_enemy_init();
    game->enemy_count = 0;
    game->hud = hud_init();
    game->weapons = weapons_init();
    game->weapons_count = 0;
    game->add_enemy = sfClock_create();
    game->level = 1;
    game->spawn = 0;
    game->delta_charlie = init_delta_charlie();
    game->music = init_music("assets/music/game.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    return (game);
}
