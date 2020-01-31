/*
** EPITECH PROJECT, 2019
** move_right
** File description:
** move_right
*/

#include "my.h"

char *move_right_case_one(char *map, infos_t *inf, int i)
{
    if (inf->state_p == 0)
        map[i] = ' ', map[i + 1] = 'P';
    else
        map[i] = 'O', map[i + 1] = 'P', inf->state_p = 0;
    return (map);
}

char *move_right_case_two(char *map, infos_t *inf, int i)
{
    get_box(inf, i + 1);
    if (inf->state_p == 0) {
        move_box_right(inf, i + 1);
        map[i] = ' ', map[i + 1] = 'P', map[i + 2] = 'X';
    }
    else {
        move_box_right(inf, i + 1);
        map[i] = 'O', map[i + 1] = 'P', map[i + 2] = 'X';
        inf->state_p = 0;
    }
    if (inf->current_box->state == 1) {
        inf->state_p = 1;
        inf->current_box->state = 0;
    }
    return (map);
}

char *move_right_case_three(char *map, infos_t *inf, int i)
{
    if (inf->state_p == 1)
        map[i] = 'O', map[i + 1] = 'P';
    else
        map[i] = ' ', map[i + 1] = 'P', inf->state_p = 1;
    return (map);
}

char *move_right_exeption(char *map, infos_t *inf, int i)
{
    if (inf->state_p == 0) {
        move_box_right(inf, i + 1);
        map[i] = ' ', map[i + 1] = 'P', map[i + 2] = 'X';
        inf->current_box->state = 1;
    }
    else {
        move_box_right(inf, i + 1);
        map[i] = 'O', map[i + 1] = 'P', map[i + 2] = 'X';
        inf->current_box->state = 1;
        inf->state_p = 0;
    }
    return (map);
}

char *move_right_case_four(char *map, infos_t *inf, int i)
{
    get_box(inf, i + 1);
    if (inf->current_box->state == 0) {
        map = move_right_exeption(map, inf, i);
    }
    else {
        if (inf->state_p == 1) {
            move_box_right(inf, i + 1);
            map[i] = 'O', map[i + 1] = 'P', map[i + 2] = 'X';
        }
        else{
            move_box_right(inf, i + 1);
            map[i] = ' ', map[i + 1] = 'P', map[i + 2] = 'X';
        }
        inf->state_p = 1;
    }
    return (map);
}