/*
** EPITECH PROJECT, 2019
** navy
** File description:
** navy
*/

#ifndef NAVY_H
#define NAVY_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "my.h"

#define ABSOLUTE(value) ((value > 0) ? (value) : (-value))

char *load_file_in_mem(char const *filepath);
char **load_file_in_2d_array(char const *filepath);

bool is_line_valid(char **content, int line);
bool check_file_errors(char **content);

int add_ship_to_map(char const *line, char **map);
char **initialize_map(void);
char **get_map_from_file(char const *filepath);

int get_usr_input(void);

void print_map(char** map);

void print_game(char** map, char** enemy_map);

int run_server(char** map);
int run_client(char** map, int pid);

int stock_bits(bool get, bool bit);
int stock_pid(int pid, bool stock);

int send_signal(int sig, int pid);

int wait_signal(int code, void (*callback)(void));
int define_signalhandler(void);

int gameover(char** map);

void hit(char** map, int x, int y);
void missed(char** map, int x, int y);
int verify_local_attack(char** map, int x, int y);

int send_attack(char** enemy_map, int pid);

int wait_for_attack(char **map, int pid);

#endif
