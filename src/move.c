/*
** EPITECH PROJECT, 2019
** move
** File description:
** move
*/

#include "my.h"

char *move_up(char *map, infos_t *inf)
{
    int i = 0, j = my_strlen(map, 0);
    for (; map[i] != 'P'; i++);
    if (map[i - j] == ' ')
        map = move_up_case_one(map, inf, i, j);
    if (map[i - j] == 'X' && map[i - j - j] == ' ')
        map = move_up_case_two(map, inf, i, j);
    if (map[i - j] == 'O')
        map = move_up_case_three(map, inf, i, j);
    if (map[i - j] == 'X' && map[i - j - j] == 'O')
        map = move_up_case_four(map, inf, i, j);
    return (map);
}

char *move_down(char *map, infos_t *inf)
{
    int i = 0, j = my_strlen(map, 0);
    for (; map[i] != 'P'; i++);
    if (map[i + j] == ' ')
        map = move_down_case_one(map, inf, i, j);
    if (map[i + j] == 'X' && map[i + j + j] == ' ')
        map = move_down_case_two(map, inf, i, j);
    if (map[i + j] == 'O')
        map = move_down_case_three(map, inf, i, j);
    if (map[i + j] == 'X' && map[i + j + j] == 'O')
        map = move_down_case_four(map, inf, i, j);
    return (map);
}

char *move_left(char *map, infos_t *inf)
{
    int i = 0;
    for (; map[i] != 'P'; i++);
    if (map[i - 1] == ' ')
        map = move_left_case_one(map, inf, i);
    if (map[i - 1] == 'X' && map[i - 2] == ' ')
        map = move_left_case_two(map, inf, i);
    if (map[i - 1] == 'O')
        map = move_left_case_three(map, inf, i);
    if (map[i - 1] == 'X' && map[i - 2] == 'O')
        map = move_left_case_four(map, inf, i);
    return (map);
}

char *move_right(char *map, infos_t *inf)
{
    int i = 0;
    for (; map[i] != 'P'; i++);
    if (map[i + 1] == ' ')
        map = move_right_case_one(map, inf, i);
    if (map[i + 1] == 'X' && map[i + 2] == ' ')
        map = move_right_case_two(map, inf, i);
    if (map[i + 1] == 'O')
        map = move_right_case_three(map, inf, i);
    if (map[i + 1] == 'X' && map[i + 2] == 'O')
        map = move_right_case_four(map, inf, i);
    return (map);
}