/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Warrior_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Warrior.hpp"

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

Test(Warrior, new) {
    OSRedirector oss(std::cout);

    Warrior w("poney", 42);
    cr_assert_eq(oss.getContent(), "poney Created\nI'm poney KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\n");
}

Test(Warrior, RangeAttack) {
    OSRedirector oss(std::cout);
    Warrior w("poney", 42);
    int got = w.RangeAttack();

    cr_assert(got == 5 + 12);
    cr_assert_eq(oss.getContent(), "poney Created\nI'm poney KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nponey intercepts\n");
    cr_assert(w.getPower() == 90);
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    w.RangeAttack();
    cr_assert_eq(oss.getContent(), "poney Created\nI'm poney KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey intercepts\nponey out of power\n");
}

Test(Warrior, CloseAttack) {
    OSRedirector oss(std::cout);
    Warrior w("poney", 42);
    int got = w.CloseAttack();

    cr_assert(got == 20 + 12);
    cr_assert_eq(oss.getContent(), "poney Created\nI'm poney KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG\nponey strikes with his hammer\n");
    cr_assert(w.getPower() == 70);
    w.CloseAttack();
    w.CloseAttack();
    got = w.CloseAttack();
    cr_assert(got == 0);
}