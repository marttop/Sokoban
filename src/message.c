/*
** EPITECH PROJECT, 2019
** message
** File description:
** message
*/

#include "my.h"

void message(void)
{
    write(1, "USAGE\n", 6);
    write(1, "        ./my_sokoban ~/your/filepath\n", 37);
    write(1, "DESCRIPTION\n", 12);
    write(1, "        Sokoban game\n", 21);
}