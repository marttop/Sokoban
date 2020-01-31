/*
** EPITECH PROJECT, 2019
** get_box
** File description:
** get_box
*/

#include "my.h"

void move_box_left(infos_t *inf, int pos)
{
    box_t *temp_node = inf->boxx;
    for (; temp_node->pos != pos;)
        temp_node = temp_node->next;
    temp_node->pos -= 1;
}

void move_box_right(infos_t *inf, int pos)
{
    box_t *temp_node = inf->boxx;
    for (; temp_node->pos != pos;)
        temp_node = temp_node->next;
    temp_node->pos += 1;
}

void move_box_up(infos_t *inf, int pos)
{
    box_t *temp_node = inf->boxx;
    for (; temp_node->pos != pos && temp_node->next != NULL;)
        temp_node = temp_node->next;
    temp_node->pos -= inf->len_line;
}

void move_box_down(infos_t *inf, int pos)
{
    box_t *temp_node = inf->boxx;
    for (; temp_node->pos != pos;)
        temp_node = temp_node->next;
    temp_node->pos += inf->len_line;
}