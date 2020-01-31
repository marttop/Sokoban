/*
** EPITECH PROJECT, 2019
** init_node
** File description:
** init_node
*/

#include "my.h"

box_t *init_node(box_t *node, int i)
{
    box_t *next_node = malloc(sizeof(box_t));
    next_node->state = 0;
    next_node->pos = i;
    next_node->next = node;
    return (next_node);
}

void get_x(infos_t *inf, char *map)
{
    int i = 0;
    box_t *node = NULL;
    for (; map[i] != '\0'; i++) {
        if (map[i] == 'X') {
            node = init_node(node, i);
        }
    }
    inf->boxx = node;
}

void get_box(infos_t *inf, int index)
{
    box_t *temp_node = inf->boxx;
    for (; temp_node->pos != index;) {
        temp_node = temp_node->next;
    }
    inf->current_box = temp_node;
}