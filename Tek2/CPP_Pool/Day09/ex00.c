/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex00
*/

#include "ex00.h"

cthulhu_t *new_cthulhu()
{
    cthulhu_t* new = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(new);
    return (new);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %i\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power < 42) {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
        return;
    }
    printf("%s attacks and destroys the city\n", this->m_name);
    this->m_power -= 42;
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t* new = malloc(sizeof(koala_t));

    koala_initializer(new, name, is_a_legend);
    return (new);
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    printf("----\n");
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("Building %s\n", this->m_name);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
	cthulhu_initializer(&this->m_parent);
	this->m_parent.m_name = strdup(_name);
    this->m_parent.m_power = _is_A_Legend ? 42 : 0;
	this->m_is_a_legend = _is_A_Legend;

	printf("Building %s\n", this->m_parent.m_name);
}

// int main () {
//     koala_t *_lkoala = new_koala("Legend", 1);
//     koala_t *_nlkoala = new_koala("NotLegend", 0);
//     cthulhu_t *_cthulhu = new_cthulhu();

//     printf("----Start----\n"); 
//     print_power(_cthulhu);
//     print_power(&_lkoala->m_parent);
//     print_power(&_nlkoala->m_parent);
//     attack(_cthulhu);
//     attack(&_lkoala ->m_parent);
//     attack(&_nlkoala ->m_parent);
//     eat(_nlkoala);
//     attack(_cthulhu);
//     sleeping(_cthulhu);
//     print_power(_cthulhu);
//     attack(&_nlkoala ->m_parent);
//     return 0;
// }