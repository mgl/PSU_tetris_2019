/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_set_keys
*/

#include "tetris.h"
#include <criterion/criterion.h>

Test(set_keys, error)
{
    tetris_t *tetris = init_tetris(NULL);
    int res = set_keys(tetris, "i", 'k');

    cr_assert_eq(res, ERROR);
}

Test(set_keys, le)
{
    tetris_t *tetris = init_tetris(NULL);
    int res = set_keys(tetris, "i", 'l');

    cr_assert_eq(tetris->k_left, 'i');
    cr_assert_eq(res, SUCCESS);
}

Test(set_keys, r)
{
    tetris_t *tetris = init_tetris(NULL);
    int res = set_keys(tetris, "1", 'r');

    cr_assert_eq(tetris->k_right, '1');
    cr_assert_eq(res, SUCCESS);
}

Test(set_keys, t)
{
    tetris_t *tetris = init_tetris(NULL);
    int res = set_keys(tetris, "o", 't');

    cr_assert_eq(tetris->k_turn, 'o');
    cr_assert_eq(res, SUCCESS);
}

Test(set_keys, q)
{
    tetris_t *tetris = init_tetris(NULL);
    int res = set_keys(tetris, " ", 'q');

    cr_assert_eq(tetris->k_quit, ' ');
    cr_assert_eq(res, SUCCESS);
}

Test(set_keys, p)
{
    tetris_t *tetris = init_tetris(NULL);
    int res = set_keys(tetris, "$", 'p');

    cr_assert_eq(tetris->k_pause, '$');
    cr_assert_eq(res, SUCCESS);
}