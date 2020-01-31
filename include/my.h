/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct box {
    int pos;
    int state;
    struct box *next;
} box_t;

typedef struct infos {
    int state_p;
    int state_x;
    int win;
    int lose;
    int nb_x;
    char *filepath;
    int len_line;
    int lines;
    int middle_x;
    int middle_y;
    box_t *boxx;
    box_t *current_box;
} infos_t;

char *get_file(char const *);
int get_biggest_line(char *);
char *adapt(char const *);
int is_sokoban(char);
void print_map(char *, infos_t *);
int my_strlen(char *, int);
void message(void);
box_t *init_node(box_t *, int);
void get_x(infos_t *, char *);
void get_box(infos_t *, int);
void init_struct(infos_t *, char *, char *);
void game_loop(int, infos_t *, WINDOW *, char *);
int win(infos_t *);
int lose(infos_t *, char *);

char *move_up(char *, infos_t *);
char *move_up_case_one(char *, infos_t *, int, int);
char *move_up_case_two(char *, infos_t *, int, int);
char *move_up_case_three(char *, infos_t *, int, int);
char *move_up_case_four(char *, infos_t *, int , int );
char *move_up_exeption(char *, infos_t *, int, int);

char *move_down(char *, infos_t *);
char *move_down_case_one(char *, infos_t *, int, int);
char *move_down_case_two(char *, infos_t *, int, int);
char *move_down_case_three(char *, infos_t *, int, int);
char *move_down_case_four(char *, infos_t *, int , int );
char *move_down_exeption(char *, infos_t *, int, int);

char *move_right(char *, infos_t *);
char *move_right_case_one(char *, infos_t *, int);
char *move_right_case_two(char *, infos_t *, int);
char *move_right_case_three(char *, infos_t *, int);
char *move_right_case_four(char *, infos_t *, int);
char *move_right_exeption(char *, infos_t *, int);

char *move_left(char *, infos_t *);
char *move_left_case_one(char *, infos_t *, int);
char *move_left_case_two(char *, infos_t *, int);
char *move_left_case_three(char *, infos_t *, int);
char *move_left_case_four(char *, infos_t *, int);
char *move_left_exeption(char *, infos_t *, int);

void move_box_left(infos_t *, int);
void move_box_right(infos_t *, int);
void move_box_up(infos_t *, int);
void move_box_down(infos_t *, int);


int get_nb_lines(char *);
int get_nb_x(char *);
void move_player(int, char *, infos_t *, WINDOW *);

#endif
