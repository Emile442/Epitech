/*
** EPITECH PROJECT, 2020
** cpp_d03_2019
** File description:
** Ex00
*/

#include "string.h"

static void string_init2(string_t *this)
{
    this->to_int = &to_int;
}

void string_init(string_t *this, const char *s)
{
    this->str = NULL;
    if (s)
        this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    string_init2(this);
}

void string_destroy(string_t *this)
{
    if (this->str)
        free(this->str);
    this->str = NULL;
}
