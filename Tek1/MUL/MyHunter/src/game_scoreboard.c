/*
** EPITECH PROJECT, 2018
** game_scoreboard
** File description:
** Game Scorebaord
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "my_hunter.h"
#include "my.h"

void init_scoreboard(window_t *current)
{
    sfVector2f text_score_coord = {300, 917};

    current->status = 0;
    current->lives = 3;
    current->score = 0;
    current->scoreboard->font = sfFont_createFromFile("font/Arial-Regular.ttf");
    current->scoreboard->text = sfText_create();
    sfText_setString(current->scoreboard->text, int_to_str(current->score));
    sfText_setFont(current->scoreboard->text, current->scoreboard->font);
    sfText_setCharacterSize(current->scoreboard->text, 50);
    sfText_move(current->scoreboard->text, text_score_coord);
}