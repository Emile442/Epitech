/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex03_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "ex03.hpp"

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;


    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

// OSRedirector oss(std::cout);
// cr_assert_eq(oss.getContent(), "assert");

Test(ex03, print)
{
    OSRedirector oss(std::cout);

    ::print("Bonjour");
    cr_assert_eq(oss.getContent(), "Bonjour\n");
}

Test(ex03, foreach_int)
{
    OSRedirector oss(std::cout);

    int tab[] = { 11, 3, 89, 42 };
    foreach(tab, print<int>, 4);
    cr_assert_eq(oss.getContent(), "11\n3\n89\n42\n");
}

Test(ex03, foreach_char)
{
    OSRedirector oss(std::cout);

    std::string tab[] = { "j'", "aime", "les", "templates", "!" };
    foreach(tab, print, 5);
    cr_assert_eq(oss.getContent(), "j'\naime\nles\ntemplates\n!\n");
}
