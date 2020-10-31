/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** turn/player
*/

#include "my.h"
#include "matchstick.h"

static bool is_nbr(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 48 || str[i] > 57) && str[i] != '\n')
            return (false);
    return (true);
}

static int get_value(turn_t* turn)
{
    char* buffer = NULL;
    size_t len = 0;
    int c;
    int tmp;

    c = getline(&buffer, &len, stdin);
    if (c == -1) {
        turn->status = -1;
        return (3);
    }
    tmp = my_getnbr(buffer);
    if ((tmp == 0 && buffer[0] != '0') || !is_nbr(buffer))
        tmp = -1;
    free(buffer);
    return (tmp);
}

static int get_line(turn_t*turn, int limit, char** map)
{
    int value = 0;

    my_printf("Line: ");
    value = get_value(turn);
    if (turn->status == -1)
        return (-1);
    while (!can_select_line(map, value, limit)) {
        if (value < 0)
            my_printf("Error: invalid input (positive number expected)\n");
        else
            my_printf("Error: this line is out of range\n");
        my_printf("Line: ");
        value = get_value(turn);
    }
    return (value);
}

static int get_matches(turn_t* turn, char* line, int limit)
{
    int value = 0;

    my_printf("Matches: ");
    value = get_value(turn);
    if (turn->status == -1)
        return (-1);
    while (!map_can_supr(line, value, limit)) {
        if (value < 0)
            my_printf("Error: invalid input (positive number expected)\n");
        else if (value == 0)
            my_printf("Error: you have to remove at least one match\n");
        if (value > limit)
            my_printf("Error: you cannot remove more than %d matches per turn\n"
            , limit);
        else if (value > count_line_stick(line))
            my_printf("Error: not enough matches on this line\n");
        return (-1);
    }
    return (value);
}

int player_turn(game_t* game)
{
    turn_t* turn = malloc(sizeof(turn_t));

    my_printf("\nYour turn:\n");
    turn->match = -1;
    turn->status = 0;
    while (turn->match == -1) {
        turn->line = get_line(turn, game->map_size, game->map);
        if (turn->status == -1)
            return (-1);
        turn->match = get_matches(turn, game->map[turn->line], \
        game->match_limit);
        if (turn->status == -1)
            return (-1);
    }
    my_printf("Player removed %d match(es) from line %d\n", turn->match, \
    turn->line);
    map_remove(game->map, turn->line, turn->match);
    free(turn);
    map_print(game->map);
    return (0);
}
