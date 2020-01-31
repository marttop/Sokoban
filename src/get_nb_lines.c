/*
** EPITECH PROJECT, 2019
** nblines
** File description:
** nblines
*/

#include "my.h"

int get_nb_lines(char *map)
{
    int i = 0, x = 0;

    for (; map[x] != '\0'; x++) {
        if (map[x] == '\n')
            i++;
    }
    return (i);
}