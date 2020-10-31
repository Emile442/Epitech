/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Display
*/

#include "my.h"
#include "my_ls.h"

static void display_line(file_t* file)
{
    display_acl(file->acl);
    my_printf(" %d", file->nlink);
    my_printf(" %s %s ", file->owner_name, file->group_name);
    my_printf(" %d", file->size);
    my_printf(" %s", file->datetime);
    my_printf(" %s", file->filename);
}

void display_list(option_t *options, list_t* list)
{
    list_t *current = list;

    if (options->print_path)
        my_printf("%s:\n", options->path);
    if (options->l_l && !options->d)
        my_printf("total %d\n", options->tt_block / 2);
    while (current) {
        if (options->l_l)
            display_line(current->file);
        else
            my_printf("%s", current->file->filename);
        my_putchar('\n');
        current = current->next;
    }
    free(list);
}
