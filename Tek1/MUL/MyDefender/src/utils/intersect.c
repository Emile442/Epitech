/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** intersect
*/

#include "my_defender.h"

bool check_colision(sfSprite* sprite1, sfSprite* sprite2)
{
    sfFloatRect sp1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect sp2 = sfSprite_getGlobalBounds(sprite2);

    if (sfFloatRect_intersects(&sp1, &sp2, NULL) == sfTrue)
        return (true);
    return (false);
}
