/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include "my.h"

Test(test_move_win, test1)
{
    infos_t inf;
    char *map = adapt("tests/test_map3.txt");
    int is = is_sokoban('X');
    int isn = is_sokoban('S');
    int won, lost;
    inf.state_p = 0, get_x(&inf, map), inf.nb_x = get_nb_x(map);
    map = move_right(map, &inf), map = move_down(map, &inf);
    map = move_down(map, &inf), map = move_right(map, &inf);
    map = move_down(map, &inf), map = move_left(map, &inf);
    won = win(&inf);
    lost = lose(&inf, map);
    cr_assert_eq(is, 0);
    cr_assert_eq(isn, 1);
    cr_assert_eq(won, 1);
    cr_assert_eq(lost, 0);
    free(map);
}

Test(basic_move_lose, test2)
{
    infos_t inf;
    int lost, won;
    char *map = adapt("tests/test_map.txt");
    int is = is_sokoban('X');
    int isn = is_sokoban('S');
    inf.state_p = 0, get_x(&inf, map), inf.nb_x = get_nb_x(map);
    inf.len_line = my_strlen(map, 0);
    map = move_up(map, &inf), map = move_up(map, &inf);
    map = move_up(map, &inf), map = move_up(map, &inf);
    map = move_up(map, &inf), map = move_up(map, &inf);
    won = win(&inf);
    lost = lose(&inf, map);
    cr_assert_eq(is, 0);
    cr_assert_eq(isn, 1);
    cr_assert_eq(lost, 1);
    cr_assert_eq(won, 0);
    free(map);
}

Test(basic_move_up, test3)
{
    infos_t inf;
    int lost, won;
    char *map = adapt("tests/test_map2.txt");
    int is = is_sokoban('X');
    int isn = is_sokoban('S');
    inf.state_p = 0, get_x(&inf, map), inf.nb_x = get_nb_x(map);
    inf.len_line = my_strlen(map, 0);
    map = move_down(map, &inf), map = move_down(map, &inf);
    map = move_down(map, &inf), map = move_down(map, &inf);
    map = move_down(map, &inf), map = move_down(map, &inf);
    lost = lose(&inf, map);
    won = win(&inf);
    cr_assert_eq(is, 0);
    cr_assert_eq(isn, 1);
    cr_assert_eq(won, 0);
    cr_assert_eq(lost, 1);
    free(map);
}

Test(basic_move_left, test4)
{
    infos_t inf;
    int lost, won;
    char *map = adapt("tests/test_map_left.txt");
    int is = is_sokoban('X');
    int isn = is_sokoban('S');
    inf.state_p = 0, get_x(&inf, map), inf.nb_x = get_nb_x(map);
    inf.len_line = my_strlen(map, 0);
    map = move_left(map, &inf), map = move_left(map, &inf);
    map = move_left(map, &inf), map = move_left(map, &inf);
    map = move_left(map, &inf), map = move_left(map, &inf);
    lost = lose(&inf, map);
    won = win(&inf);
    cr_assert_eq(is, 0);
    cr_assert_eq(isn, 1);
    cr_assert_eq(won, 0);
    cr_assert_eq(lost, 0);
    free(map);
}

Test(basic_move_right, test5)
{
    infos_t inf;
    int lost, won;
    char *map = adapt("tests/test_map_right.txt");
    int is = is_sokoban('X');
    int isn = is_sokoban('S');
    inf.state_p = 0, get_x(&inf, map), inf.nb_x = get_nb_x(map);
    inf.len_line = my_strlen(map, 0);
    map = move_right(map, &inf), map = move_right(map, &inf);
    map = move_right(map, &inf), map = move_right(map, &inf);
    map = move_right(map, &inf), map = move_right(map, &inf);
    lost = lose(&inf, map);
    won = win(&inf);
    cr_assert_eq(is, 0);
    cr_assert_eq(isn, 1);
    cr_assert_eq(won, 0);
    cr_assert_eq(lost, 0);
    free(map);
}