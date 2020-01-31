/*
** EPITECH PROJECT, 2019
** move_down
** File description:
** move_down
*/

#include "my.h"

char *move_down_case_one(char *map, infos_t *inf, int i, int j)
{
    if (inf->state_p == 0)
        map[i] = ' ', map[i + j] = 'P';
    else
        map[i] = 'O', map[i + j] = 'P', inf->state_p = 0;
    return (map);
}

char *move_down_case_two(char *map, infos_t *inf, int i, int j)
{
    get_box(inf, i + j);
    if (inf->state_p == 0) {
        move_box_down(inf, i + j);
        map[i] = ' ', map[i + j] = 'P', map[i + j + j] = 'X';
    }
    else {
        move_box_down(inf, i + j);
        map[i] = 'O', map[i + j] = 'P', map[i + j + j] = 'X';
        inf->state_p = 0;
    }
    if (inf->current_box->state == 1) {
        inf->state_p = 1;
        inf->current_box->state = 0;
    }
    return (map);
}

char *move_down_case_three(char *map, infos_t *inf, int i, int j)
{
    if (inf->state_p == 0)
        map[i] = ' ', map[i + j] = 'P', inf->state_p = 1;
    else
        map[i] = 'O', map[i + j] = 'P';
    return (map);
}

char *move_down_exeption(char *map, infos_t *inf, int i, int j)
{
    if (inf->state_p == 0) {
        move_box_down(inf, i + j);
        map[i] = ' ', map[i + j] = 'P', map[i + j + j] = 'X';
        inf->current_box->state = 1;
    }
    else {
        move_box_down(inf, i + j);
        map[i] = 'O', map[i + j] = 'P', map[i + j + j] = 'X';
        inf->current_box->state = 1;
        inf->state_p = 0;
    }
    return (map);
}

char *move_down_case_four(char *map, infos_t *inf, int i, int j)
{
    get_box(inf, i + j);
    if (inf->current_box->state == 0) {
        map = move_down_exeption(map, inf, i, j);
    }
    else {
        if (inf->state_p == 1) {
            move_box_down(inf, i + j);
            map[i] = 'O', map[i + j] = 'P', map[i + j + j] = 'X';
        }
        else{
            move_box_down(inf, i + j);
            map[i] = ' ', map[i + j] = 'P', map[i + j + j] = 'X';
        }
        inf->state_p = 1;
    }
    return (map);
}