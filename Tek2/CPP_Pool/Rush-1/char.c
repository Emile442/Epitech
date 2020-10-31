/*
** EPITECH PROJECT, 2020
** char.c
** File description:
** char
*/

#include <stdio.h>
#include <stdarg.h>

#include "char.h"
#include "new.h"

typedef struct
{
    Class   base;
    char     c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!args)
        return;
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        return;
    if (!this->base.__str__)
        free(this->base.__str__);
    if (!this->base.__add__)
        free(this->base.__add__);
    if (!this->base.__sub__)
        free(this->base.__sub__);
}

Object *Char_add(CharClass *this, CharClass *c2)
{
    Object *cres = new(Char, this->c + c2->c);

    return (cres);
}

Object *Char_sub(CharClass *this, CharClass *c2)
{
    Object *cres = new(Char, this->c - c2->c);

    return (cres);
}

Object *Char_mul(CharClass *this, CharClass *c2)
{
    Object *cres = new(Char, this->c * c2->c);

    return (cres);
}

Object *Char_div(CharClass *this, CharClass *c2)
{
    Object *cres = NULL;

    if (c2->c == 0)
        raise("Div by zero !");
    cres = new(Char, this->c / c2->c);

    return (cres);
}

bool Char_eq(CharClass *this, CharClass *c2)
{
    return (this->c == c2->c);
}

bool Char_gt(CharClass *this, CharClass *c2)
{
    return (this->c > c2->c);
}

bool Char_lt(CharClass *this, CharClass *c2)
{
    return (this->c < c2->c);
}

char *Char_str(CharClass *this)
{
    size_t size = 1 + strlen(this->base.__name__)\
 + 2 + strlen("< ()>");
    char *dest = malloc(sizeof(char) * size + 2);

    if (!dest)
        raise ("Malloc failed");
    if (snprintf(dest, size, "<%s (%c)>", this->base.__name__, this->c) < 0)
        raise ("snprintf failed");
    return (dest);
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0
};

const Class   *Char = (const Class *)&_description;
