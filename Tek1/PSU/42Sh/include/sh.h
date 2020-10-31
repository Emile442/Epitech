/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** Main header
*/

#ifndef MAIN_H
#define MAIN_H

#define ERROR 84
#define MAX_FCT 10

//Include my library
#include <my.h>

//Include standard libraries
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

//Include other headers
#include <const.h>
#include <check_error.h>

//Structure
typedef struct data_s {
    char* key;
    char* value;
} data_t;

typedef struct list_s {
    data_t* data;
    struct list_s *next;
} list_t;

typedef struct shell_s {
    bool exit;
    int code;
    char **env;
    char **all_commands;
    char **command;
    int *fd_pipe;
    list_t* alias;
} shell_t;

typedef struct fct_tab_s
{
    char *str;
    char **(*fct)(shell_t* shell);
} fct_tab_t;

//Prototypes

int mysh_loop(shell_t* shell);
int multiple_exec(shell_t *shell, int i);
int make_basic_cmd(shell_t* shell);
char **get_path(char **env);
void free_dchar(char** array);
char **get_path(char **env);

char** make_repeat(shell_t* shell);
char** make_unalias(shell_t* shell);
char **make_alias(shell_t* shell);
char** make_which(shell_t* shell);
char **make_echo(shell_t* shell);
char **make_chdir(shell_t* shell);
char **make_env(shell_t* shell);
char **make_setenv(shell_t* shell);
char **make_unsetenv(shell_t* shell);
char **make_exit(shell_t* shell);
char **chdir_env(char *path, shell_t* shell);
char **remove_from_env(int nb, char **env);
char *check_setenv(shell_t* shell);
char *give_env_path(char *to_find, char **env, char *arg);

void replace_alias(shell_t* shell);

int execute_cmd(shell_t* shell, char **path);
char **line_formating(char *str);
char *find_base_cmd(char *cmd, char **path);
char **get_path(char **env);
char *find_simple_cmd(char *str);

int count_list(list_t **list);
void reverse_list(list_t **list);
void push_list(list_t **list, data_t* data);
void pull_list(list_t **list);
void print_list(list_t **list);

bool search_list(list_t **list, char* str);
bool str_have(char* str, char c);

int pre_exec(shell_t* shell, char* prompt);
bool is_builtins(char* cmd);
char** init_env(void);
void default_env(shell_t* shell);

char **parse_prompt(char *prompt);
int manage_separator(shell_t *shell, int i, int state);
int check_redirect_str(char *prompt, int count);
char *return_redirect_str(char *prompt, int count);
int cmds_size(char *prompt);

//Define
# define CURRENT_CMD(shell) (shell->all_commands[i])
# define NEXT_CMD(shell) (shell->all_commands[i + 1])

#endif
