/*
** EPITECH PROJECT, 2020
** verte.c
** File description:
** int
*/

#include <stdio.h>
#include <stdarg.h>

#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!args)
        return;
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
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

static int count_int_size(int value)
{
    int count = 0;

    if (value < 0)
        count = 1;
    while (value != 0) {
        value /= 10;
        count++;
    }
    return (count);
}

Object *Int_add(IntClass *this, IntClass *i2)
{
    Object *ires = new(Int, this->x + i2->x);

    return (ires);
}

Object *Int_sub(IntClass *this, IntClass *i2)
{
    Object *ires = new(Int, this->x - i2->x);

    return (ires);
}

Object *Int_mul(IntClass *this, IntClass *i2)
{
    Object *ires = new(Int, this->x * i2->x);

    return (ires);
}

Object *Int_div(IntClass *this, IntClass *i2)
{
    Object *ires = NULL;

    if (i2->x == 0)
        raise("Div by zero !");
    ires = new(Int, this->x / i2->x);
    return (ires);
}

bool Int_eq(IntClass *this, IntClass *i2)
{
    return (this->x == i2->x);
}

bool Int_gt(IntClass *this, IntClass *i2)
{
    return (this->x > i2->x);
}

bool Int_lt(IntClass *this, IntClass *i2)
{
    return (this->x < i2->x);
}

char *Int_str(IntClass *this)
{
    size_t size = count_int_size(this->x) + strlen(this->base.__name__) + \
    2 + strlen("< ()>");
    char *dest = malloc(sizeof(char) * size + 2);

    if (!dest)
        raise ("Malloc failed");
    if (snprintf(dest, size, "<%s (%d)>", this->base.__name__, this->x) < 0)
        raise ("snprintf failed");
    return (dest);
}

// Create additional functions here

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .x = 0,
};

const Class   *Int = (const Class *)&_description;
