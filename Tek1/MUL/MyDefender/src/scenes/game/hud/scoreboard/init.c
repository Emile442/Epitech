/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scoreboard/init.c
*/

#include "my_defender.h"

text_t* init_text(char* title, sfVector2f position)
{
    text_t* text = malloc(sizeof(text_t));

    text->value = 0;
    text->update = sfClock_create();
    text->font = sfFont_createFromFile("assets/fonts/zcool.ttf");
    text->text = sfText_create();
    sfText_setString(text->text, str_with_num(title, 12));
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, 60);
    sfText_move(text->text, position);
    return (text);
}

info_t* init_info(void)
{
    info_t* infos = malloc(sizeof(info_t));

    infos->score = init_text("Score: ", (sfVector2f){10, 10});
    infos->money = init_text("Money: $", (sfVector2f){10, 100});
    infos->level = init_text("Level: ", (sfVector2f){10, 200});
    infos->level->value = 1;
    infos->money->value = 200;
    return (infos);
}
