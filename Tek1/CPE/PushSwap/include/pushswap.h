/*
** EPITECH PROJECT, 2018
** pushswap
** File description:
** pushswap
*/
#include <stdbool.h>

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

typedef struct list_s {
    int value;
    struct list_s *next;
} list_t;

void reverse_list(list_t** list);
void push_list(list_t** list, int value);
void pull_list(list_t** list);
int count_list(list_t **list);
int found_the_smaller(list_t *list);
void ra(list_t **list);
void pb(list_t **src, list_t **dest);
void pa(list_t **src, list_t **dest);
bool check_already_order(list_t *list_a);

#endif /* !PUSHSWAP_H_ */
