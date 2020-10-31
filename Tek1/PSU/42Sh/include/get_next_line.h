/*
** EPITECH PROJECT, 2019
** Get_next_line
** File description:
** get next line header
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

//Define Read size
#ifndef READ_SIZE
#define READ_SIZE 5
#endif

//Include standard libraries
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Prototype
char *get_next_line(int fd);

#endif
