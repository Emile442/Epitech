/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2018
** File description:
** turn/ia
*/

#include "my.h"
#include "matchstick.h"

static int pair_to_impair(game_t* game, int line_nbr)
{
    int tmp = game->match_limit;

    if (is_pair(game->match_limit)) {
        if (!is_pair(tmp))
            tmp --;
        for (; !map_can_supr(game->map[line_nbr], tmp, game->match_limit); \
        tmp -= 2);
    } else {
        if (is_pair(tmp))
            tmp--;
        for (; !map_can_supr(game->map[line_nbr], tmp, game->match_limit); \
        tmp -= 2);
    }
    if (count_line_have_stick(game->map) <= 3 && tmp != 1)
        tmp--;
    return (tmp);
}

static void stategic_ia(turn_t* turn, game_t* game, int big_line, int l_stick)
{
    int nbr_matches = count_line_stick(game->map[big_line]);

    turn->line = big_line;
    if (l_stick == 1 && nbr_matches == 1)
        turn->match = 1;
    else if (count_line_have_stick(game->map) == 2 \
        || count_line_stick(game->map[big_line]) <= 2)
        turn->match = 1;
    else
        turn->match = pair_to_impair(game, turn->line);
}

void ia_turn(game_t* game)
{
    turn_t* turn = malloc(sizeof(turn_t));
    int n_big_line = found_the_most_big_line(game->map);
    int n_have_stick = count_line_have_stick(game->map);

    my_printf("\nAI's turn...\n");
    stategic_ia(turn, game, n_big_line, n_have_stick);
    map_remove(game->map, turn->line, turn->match);
    my_printf("AI removed %d match(es) from line %d\n", turn->match, \
    turn->line);
    map_print(game->map);
    free(turn);
}
