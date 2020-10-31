/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"

#include "new.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!args)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (!this && !this->base.__str__)
        free(this->base.__str__);
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

Object *Point_add(PointClass *this, PointClass *v2)
{
    Object *vres = new(Point, this->x + v2->x, this->y + v2->y);

    return (vres);
}

Object *Point_sub(PointClass *this, PointClass *v2)
{
    Object *vres = new(Point, this->x - v2->x, this->y - v2->y);

    return (vres);
}

char *Point_str(PointClass *this)
{
    size_t size = count_int_size(this->x) + count_int_size(this->y) +\
    strlen(this->base.__name__) + strlen("< (, )>") + 2;
    char *dest = malloc(sizeof(char) * size + 1);

    if (!dest)
        raise ("Malloc failed");
    if (snprintf(dest, size, "<%s (%d, %d)>", this->base.__name__, this->x,\
this->y) < 0)
        raise ("snprintf failed");
    return (dest);
}
// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
