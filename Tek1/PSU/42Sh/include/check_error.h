/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** Check_error header
*/

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

//Include standard libraries
# include <errno.h>
# include <string.h>
# include <signal.h>

//Include my library
# include <my.h>

//Prototypes
int print_error(char *cmd);
int print_child_error(int status);

#endif
