/*
** EPITECH PROJECT, 2018
** test_anagram
** File description:
** Test Anagram
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"
#include "stumper.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(anagram, anagram_true, .init = redirect_all_std)
{
    char* authorised = "eielm";
    char* str = "Emile";

    anagram("moon", "moon");
    cr_assert_stdout_eq_str("anagram!\n");
}

