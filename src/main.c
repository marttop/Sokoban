/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

void init_struct(infos_t *inf, char *map, char *filepath)
{
    inf->filepath = filepath;
    inf->state_p = 0, inf->state_x = 0, inf->nb_x = get_nb_x(map);
    initscr(), inf->lines = get_nb_lines(map), get_x(inf, map);
    inf->len_line = my_strlen(map, 0);
    inf->middle_x = COLS/2 - (inf->len_line/2);
    inf->middle_y = LINES/2 - (inf->lines/2);
    inf->win = 0, inf->lose = 0;
}

void move_player(int ch, char *map, infos_t *inf, WINDOW *window)
{
    switch (ch) {
    case KEY_UP :
        map = move_up(map, inf);
        mvwprintw(window, 0, 0, map);
        break;
    case KEY_DOWN :
        map = move_down(map, inf);
        mvwprintw(window, 0, 0, map);
        break;
    case KEY_LEFT :
        map = move_left(map, inf);
        mvwprintw(window, 0, 0, map);
        break;
    case KEY_RIGHT :
        map = move_right(map, inf);
        mvwprintw(window, 0, 0, map);
        break;
    }
}

void game_loop(int ch, infos_t *inf, WINDOW *window, char *map)
{
    if (COLS > inf->len_line && LINES > inf->lines) {
        wclear(window), wrefresh(window), mvwin(window, inf->middle_y,
        inf->middle_x);
        mvwprintw(window, 0, 0, map);
        move_player(ch, map, inf, window), wrefresh(window);
    }
    else {
        clear(), wrefresh(window);
        mvprintw(LINES/2, COLS/2, "SMALL !");
        refresh();
    }
}

void print_map(char *map, infos_t *inf)
{
    int ch = 0;
    WINDOW *window = newwin(inf->lines,
    inf->len_line, inf->middle_y, inf->middle_x);
    wprintw(window, map), wrefresh(window), noecho(), keypad(window, 1);
    while (!win(inf) && !lose(inf, map)) {
        ch = wgetch(window);
        if (ch == ' ') {
            map = adapt(inf->filepath);
            get_x(inf, map), mvwprintw(window, 0, 0, map), inf->state_p = 0;
        }
        game_loop(ch, inf, window, map);
        inf->middle_x = COLS/2 - (inf->len_line/2);
        inf->middle_y = LINES/2 - (inf->lines/2);
    }
    delwin(window), endwin();
    free(map);
}

int main(int ac, char **av)
{
    char *map;
    infos_t inf;
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h'))
        message();
    else if (ac == 2) {
        map = adapt(av[1]);
        init_struct(&inf, map, av[1]);
        print_map(map, &inf);
        if (inf.win == 1) {
            return (0);
        }
    }
    else {
        write(2, "WRONG ARG", 9);
        return (84);
    }
    return (1);
}