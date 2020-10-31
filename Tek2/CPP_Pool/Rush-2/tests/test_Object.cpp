/*
** EPITECH PROJECT, 2018
** cpp_d07m_2019
** File description:
** Created by Tornike,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Object.hpp"
#include "OSRedirection.hpp"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
};

Test(Character, constructor_get_lvl_name) {
    Character c("Name_t", 69);

    cr_assert_eq(69, c.getLvl());
    cr_assert_eq("Name_t", c.getName());
}