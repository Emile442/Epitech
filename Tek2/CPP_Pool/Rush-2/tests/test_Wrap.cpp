/*
** EPITECH PROJECT, 2018
** cpp_d07m_2019
** File description:
** Created by Tornike,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Wrap.hpp"
/*#include "OSRedirection.hpp"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
};*/

Test(Wrap, Wrap_is_open) {
    Wrap w;

    cr_assert_eq(false, w.GetIsOpen());
}