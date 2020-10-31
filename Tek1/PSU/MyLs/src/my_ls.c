/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/

#include "my.h"
#include "my_ls.h"

char *get_date(struct stat file_info)
{
    char *res = malloc(sizeof(char) * 13);

    if (res == NULL)
        exit(EPI_FAILURE);
    my_memset(res, '\0', 13);
    return (my_strncat(res, ctime(&file_info.st_mtime) + 4, 12));
}

void recursive_folder(char* path, option_t* options)
{
    option_t* r_options = malloc(sizeof(option_t));

    options->print_path = true;

    r_options->path = path;
    r_options->tt_block = 0;
    r_options->print_path = true;
    r_options->l_l = options->l_l;
    r_options->t = options->t;
    r_options->r = options->r;
    r_options->d = options->d;
    r_options->r_r = options->r_r;
    my_ls(r_options);
    my_putchar('\n');
    free(r_options);
}

file_t* create_file(option_t* options, char* filename)
{
    file_t* file = malloc(sizeof(file_t));
    struct stat s;

    file->filename = malloc(sizeof(char) * my_strlen(filename) + 1);
    if (file == NULL || file->filename == NULL)
        exit(EPI_FAILURE);
    my_memset(file->filename, '\0', my_strlen(filename));
    file->filename = my_strcat(file->filename, filename);
    stat(get_file_path(options, file->filename), &s);
    file->acl = set_acl(s);
    file->nlink = s.st_nlink;
    if (options->l_l) {
        file->owner_name = getpwuid(s.st_uid)->pw_name;
        file->group_name = getgrgid(s.st_gid)->gr_name;
    }
    file->size = s.st_size;
    file->datetime = get_date(s);
    options->tt_block += s.st_blocks;
    if (file->acl->type == 'd' && options->r_r)
        recursive_folder(get_file_path(options, file->filename), options);
    return (file);
}

void my_ls(option_t* options)
{
    list_t* list = NULL;
    struct dirent *current;
    DIR *dir = opendir(options->path);

    if (dir == NULL)
        error_file_unknow(options->path);
    current = readdir(dir);
    while (current != NULL) {
        if (options->d && current->d_name[0] == '.' && \
        current->d_name[1] == '\0') {
            push_list(&list, create_file(options, current->d_name));
            break;
        }
        if (current->d_name[0] != '.')
            push_list(&list, create_file(options, current->d_name));
        current = readdir(dir);
    }
    closedir(dir);
    reverse_list(&list);
    order_list(options, &list);
    display_list(options, list);
}
