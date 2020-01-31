/*
** EPITECH PROJECT, 2019
** winnlose
** File description:
** winning and losing
*/

#include "my.h"

int win(infos_t *inf)
{
    box_t *temp_node = inf->boxx;
    int counter = 0;

    for (; temp_node != NULL;) {
        counter += temp_node->state;
        temp_node = temp_node->next;
    }
    if (counter == inf->nb_x) {
        inf->win = 1;
        return (1);
    }
    return (0);
}

int lose(infos_t *inf, char *map)
{
    box_t *temp_node = inf->boxx;
    int counter = 0;
    int i = 0, j = inf->len_line;
    for (; temp_node != NULL;) {
        i = temp_node->pos;
        if ((map[i + 1] == '#' && map[i + j] == '#') ||
        (map[i + 1] == '#' && map[i - j] == '#') ||
        (map[i - 1] == '#' && map[i - j] == '#') ||
        (map[i - 1] == '#' && map[i + j] == '#'))
            counter++;
        temp_node = temp_node->next;
    }
    if (counter == inf->nb_x) {
        inf->lose = 1;
        return (1);
    }
    return (0);
}