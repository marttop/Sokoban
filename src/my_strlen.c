/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char *str, int i)
{
    if (str == NULL)
        return (0);
    for (; str[i] != '\n'; i++);
    return (i + 1);
}