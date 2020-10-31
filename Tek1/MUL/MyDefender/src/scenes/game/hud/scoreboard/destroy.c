/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** scoreboard/destroy
*/

#include "my_defender.h"

void text_destroy(text_t* text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    sfClock_destroy(text->update);
    free(text);
}

void destroy_infos(info_t* infos)
{
    text_destroy(infos->money);
    text_destroy(infos->score);
    free(infos);
}
