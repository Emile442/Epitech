/*
** EPITECH PROJECT, 2019
** Minishell1
** File description:
** Basic commands header
*/

#ifndef BASIC_CMD_H
#define BASIC_CMD_H

//Include my library
#include <my.h>

//Include standard libraries
#include <unistd.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

//Include other header
#include <check_error.h>

//Prototypes
int execute_cmd(char **av, char **env, char **path);

#endif
