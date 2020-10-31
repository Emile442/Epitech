/*
** EPITECH PROJECT, 2018
** test_move
** File description:
** Check player has been move
*/

#include <criterion/criterion.h>

Test(env_str, con_env)
{
    char* output = "sh";
    char* expected = "sh";

    cr_assert_str_eq(output, expected);
}
