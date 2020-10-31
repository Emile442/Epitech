/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** MY_SHELL
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#ifndef MY_SHELL_H
#define MY_SHELL_H

#include "my.h"

#define ERR_CMD_NTF "Command not found."
#define ERR_PERM "Permission denied."
#define ERR_SEGV "Segmentation fault"
#define ERR_FPR "Floating exception"
#define ERR_FORMAT "Exec format error. Wrong Architecture."
#define ENV_STR "Variable name must contain alphanumeric characters."
#define ENV_U_F "Variable name must begin with a letter."
#define EXIT_ERR "Expression Syntax."

typedef struct shell_s {
    bool exit;
    int code;
    char** env;
    char** command;
} shell_t;

shell_t* init_shell(char** env);

char** parse_args(char* str);

//core/pre_exec
int exec_command(shell_t* shell);

//core/error
bool check_error(char* cmd, char* path);

int print_infos(int ac, char **splitted_cmd);

//core/dispatch
int dispatch_cmd(shell_t* shell);

//core/prompt
void prompt_loop(shell_t* shell);
char* get_env(char** env, char* target);

//utils/filehandle
char* get_file_path(char* path, char* filename);
bool file_exist(char* filepath);
char* get_current_dir(char* pwd);
bool is_directory(char* path);

//utils/validation
int my_str_correct_env(char const *str);

//env/get_env_path
char** get_env_path(char** env);

//env/init_env
char **default_env(void);
char** init_env(char** env);

//builtins/*
int exit_cmd(shell_t* shell);
int env_cmd(shell_t* shell);
int cd_cmd(shell_t* shell);
//builtins/setenv
int setenv_cmd(shell_t* shell);
char** new_env(char** env, char* key, char* value);
char** edit_env(char** env, char* key, char* value);
char* env_str(char* key, char* value);

//builtins/unsetenv
int unsetenv_cmd(shell_t* shell);

char **parse_str(char *str, char c);
void free_double_char(char** array);

#endif
