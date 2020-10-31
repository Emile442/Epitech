/*
** EPITECH PROJECT, 2019
** lemin.h
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include "my.h"

typedef struct s_n4s {
    char *buf;
    size_t len;
    ssize_t ret;
    char **get_info;
    float speed;
    float front;
    float left;
    float right;
    int i;
    float dir;
} s_n4s;

int main_loop(s_n4s *n4s);
bool start_or_stop_simulation(char *str);
char *get_command_player(void);
void rotation_car(s_n4s *n4s);
void get_info_lidar(s_n4s *n4s);
bool slow_down_speed_car(s_n4s *n4s);
void slow_down_speed_car_2(s_n4s *n4s);
void rotation_car(s_n4s *n4s);

#endif
