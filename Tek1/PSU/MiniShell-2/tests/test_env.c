/*
** EPITECH PROJECT, 2018
** test_move
** File description:
** Check player has been move
*/

#include <criterion/criterion.h>


#include "my_shell.h"

Test(env_str, con_env)
{
    char* output = env_str("EMILE", "LEPETIT");
    char* expected = "EMILE=LEPETIT";

    cr_assert_str_eq(output, expected);
}
