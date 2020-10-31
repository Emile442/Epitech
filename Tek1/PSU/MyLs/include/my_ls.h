/*
** EPITECH PROJECT, 2018
** MY_LS
** File description:
** MY_LS
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef MY_LS_H_
#define MY_LS_H_

typedef struct option_s {
    char* path;
    bool print_path;
    int tt_block;
    bool l_l;
    bool t;
    bool r;
    bool d;
    bool r_r;
} option_t;

typedef struct right_s {
    bool r;
    bool w;
    bool x;
} right_t;

typedef struct acl_s {
    char type;
    right_t* owner;
    right_t* group;
    right_t* other;
    bool t;
} acl_t;

typedef struct file_s {
    char* filename;
    acl_t* acl;
    int nlink;
    char* owner_name;
    char* group_name;
    int size;
    char* datetime;
} file_t;

typedef struct list_s {
    file_t* file;
    struct list_s *next;
} list_t;

void my_ls(option_t* options);
option_t* parse_params(char* path, char** params_s, bool print_path);

int count_list(list_t **list);
void reverse_list(list_t **list);
void push_list(list_t **list, file_t* value);
void pull_list(list_t **list);

acl_t* set_acl(struct stat sb);
void display_acl(acl_t* acl);

char* get_file_path(option_t *options, char* filename);

void display_list(option_t *options, list_t* list);
void order_list(option_t *options, list_t** list);

void my_puterror(char* str);
void error_file_unknow(char* path);

#endif /* !MY_LS_H_ */
