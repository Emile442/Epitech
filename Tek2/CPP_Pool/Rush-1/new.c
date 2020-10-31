/*
** EPITECH PROJECT, 2020
** new
** File description:
** new
*/

#include "new.h"
#include <string.h>

Object *va_new(const Class *class, va_list *ap)
{
    Object   *new_obj = malloc(class->__size__);

    if (!new_obj)
        raise ("Malloc failed");
    memcpy(new_obj, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(new_obj, ap);
    return (new_obj);
}

Object *new(const Class *class, ...)
{
    Object   *new_obj = NULL;
    va_list ap;

    va_start(ap, class);
    new_obj = va_new(class, &ap);
    va_end(ap);
    return (new_obj);
}

void delete(Object *ptr)
{
    Class *del = ptr;

    if (!ptr)
        return;
    if (del->__dtor__)
        del->__dtor__(ptr);
    free(ptr);
}