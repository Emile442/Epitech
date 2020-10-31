/*
** EPITECH PROJECT, 2020
** verte.c
** File description:
** vertex
*/

#include <stdio.h>
#include <stdarg.h>

#include "vertex.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!args)
        return;
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
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

Object *Vertex_add(VertexClass *this, VertexClass *v2)
{
    Object *vres = new(Vertex, this->x + v2->x, this->y + v2->y,\
    this->z + v2->z);

    return (vres);
}

Object *Vertex_sub(VertexClass *this, VertexClass *v2)
{
    Object *vres = new(Vertex, this->x - v2->x, this->y - v2->y,\
    this->z - v2->z);

    return (vres);
}

char *Vertex_str(VertexClass *this)
{
    size_t size = count_int_size(this->x) + count_int_size(this->y) +\
    count_int_size(this->z) + strlen(this->base.__name__)\
 + 2 + strlen("< (, , )>");
    char *dest = malloc(sizeof(char) * size + 2);

    if (!dest)
        raise ("Malloc failed");
    if (snprintf(dest, size, "<%s (%d, %d, %d)>", this->base.__name__, this->x,\
this->y, this->z) < 0)
        raise ("snprintf failed");
    return (dest);
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
