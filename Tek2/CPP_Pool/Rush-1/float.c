/*
** EPITECH PROJECT, 2020
** verte.c
** File description:
** Float
*/

#include <stdio.h>
#include <stdarg.h>

#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!args)
        return;
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
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

static float count_Float_size(float value)
{
    float count = 7;

    value = (value == 0) ? 1.1 : value;
    if (value < 0)
        count = 1;
    while (value != 0) {
        value /= 10;
        count++;
    }
    return (count);
}

Object *Float_add(FloatClass *this, FloatClass *f2)
{
    Object *fres = new(Float, this->x + f2->x);

    return (fres);
}

Object *Float_sub(FloatClass *this, FloatClass *f2)
{
    Object *fres = new(Float, this->x - f2->x);

    return (fres);
}

Object *Float_mul(FloatClass *this, FloatClass *f2)
{
    Object *fres = new(Float, this->x * f2->x);

    return (fres);
}

Object *Float_div(FloatClass *this, FloatClass *f2)
{
    Object *fres = NULL;

    if (f2->x == 0)
        raise("Div by zero !");
    fres = new(Float, this->x / f2->x);
    return (fres);
}

bool Float_eq(FloatClass *this, FloatClass *f2)
{
    return (this->x == f2->x);
}

bool Float_gt(FloatClass *this, FloatClass *f2)
{
    return (this->x > f2->x);
}

bool Float_lt(FloatClass *this, FloatClass *f2)
{
    return (this->x < f2->x);
}

char *Float_str(FloatClass *this)
{
    size_t size = count_Float_size(this->x) + strlen(this->base.__name__) + \
    2 + strlen("< ()>");
    char *dest = malloc(sizeof(char) * size + 2);

    if (!dest)
        raise ("Malloc failed");
    if (snprintf(dest, size, "<%s (%f)>", this->base.__name__, this->x) < 0)
        raise ("snprintf failed");
    return (dest);
}

// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .x = 0,
};

const Class   *Float = (const Class *)&_description;
