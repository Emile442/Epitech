/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Character.hpp"

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

Test(Character, new) {
    OSRedirector oss(std::cout);

    Character c("poney", 42);
    cr_assert_eq(oss.getContent(), "poney Created\n");
}

Test(Character, getLvl) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);

    cr_assert(c.getLvl() == 42);
}

Test(Character, getName) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);
    std::string got = c.getName();
    std::string expected = "poney";

    cr_assert(got == expected);
}

Test(Character, getPv) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);

    cr_assert(c.getPv() == 100);
}

Test(Character, getPower) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);

    cr_assert(c.getPower() == 100);
}

Test(Character, CloseAttack) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);
    int got = c.CloseAttack();

    cr_assert(got == 10 + 5);
    cr_assert_eq(oss.getContent(), "poney Created\nponey strikes with a wooden stick\n");
    cr_assert(c.getPower() == 90);
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    c.CloseAttack();
    cr_assert_eq(oss.getContent(), "poney Created\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey strikes with a wooden stick\nponey out of power\n");
}

Test(Character, RangeAttack) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);
    int got = c.RangeAttack();

    cr_assert(got == 5 + 5);
    cr_assert_eq(oss.getContent(), "poney Created\nponey tosses a stone\n");
    cr_assert(c.getPower() == 90);
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    c.RangeAttack();
    cr_assert_eq(oss.getContent(), "poney Created\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey tosses a stone\nponey out of power\n");
}

Test(Character, TakeDamage) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);

    cr_assert(c.getPv() == 100);
    c.TakeDamage(10);
    cr_assert(c.getPv() == 90);
    cr_assert_eq(oss.getContent(), "poney Created\nponey takes 10 damage\n");
    c.TakeDamage(200);
    cr_assert(c.getPv() == 0);
    cr_assert_eq(oss.getContent(), "poney Created\nponey takes 10 damage\nponey out of combat\n");
    c.TakeDamage(200);
    cr_assert(c.getPv() == 0);
    cr_assert_eq(oss.getContent(), "poney Created\nponey takes 10 damage\nponey out of combat\nponey out of combat\n");
}

Test(Character, Heal) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);

    c.TakeDamage(60);
    cr_assert(c.getPv() == 40);
    c.Heal();
    cr_assert_eq(oss.getContent(), "poney Created\nponey takes 60 damage\nponey takes a potion\n");
    cr_assert(c.getPv() == 90);
    c.Heal();
    cr_assert(c.getPv() == 100);
}

Test(Character, RestorePower) {
    OSRedirector oss(std::cout);
    Character c("poney", 42);

    c.CloseAttack();
    cr_assert(c.getPower() == 90);
    c.RestorePower();
    cr_assert(c.getPower() == 100);
    cr_assert_eq(oss.getContent(), "poney Created\nponey strikes with a wooden stick\nponey eats\n");
}

