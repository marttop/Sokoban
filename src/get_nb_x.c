/*
** EPITECH PROJECT, 2019
** get_nb_x
** File description:
** get_nb_x
*/

#include "my.h"

int get_nb_x(char *map)
{
    int i = 0, counter = 0;
    for (; map[i] != '\0'; i++) {
        if (map[i] == 'X')
            counter++;
    }
    return (counter);
}