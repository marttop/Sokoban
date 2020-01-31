/*
** EPITECH PROJECT, 2019
** get_file
** File description:
** get_file
*/

#include "my.h"

int is_sokoban(char c)
{
    return (c != 'X' && c != 'O' && c != '#' &&
    c != 'P' && c != '\n' && c != ' ');
}

char *get_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        exit(84);
    struct stat sb;
    stat(filepath, &sb);
    char *str = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, str, sb.st_size);
    str[sb.st_size] = '\0', close(fd);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_sokoban(str[i])) {
            free(str);
            exit(84);
        }
    }
    return (str);
}

int get_biggest_line(char *map)
{
    int nb_lines = get_nb_lines(map);
    int nb_columns = 0, j = 0, k = 0;
    for (int i = 0; i < nb_lines; i++) {
        for (k = 0; map[j] != '\n'; j++, k++);
        j++;
    if (nb_columns < k)
        nb_columns = k;
    }
    return (nb_columns);
}

char *adapt(char const *filepath)
{
    char *map = get_file(filepath);
    int biggest = get_biggest_line(map);
    int nb_lines = get_nb_lines(map), k = 0, j = 0, x = 0;
    char *new_map = malloc(sizeof(char) * (biggest * nb_lines + nb_lines) + 1);

    for (int i = 0; i < nb_lines; i++) {
        for (x = 0; map[j] != '\n' && map[j] != '\0'; k++, j++, x++)
            new_map[k] = map[j];
        for (; x < biggest; k++, x++)
            new_map[k] = ' ';
        new_map[k++] = '\n';
        j++;
    }
    free(map);
    new_map[k] = '\0';
    return (new_map);
}