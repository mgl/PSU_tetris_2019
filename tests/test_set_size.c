/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_set_size
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(set_size, true)
{
    tetris_t *tetris = init_tetris();
    int res = set_size(tetris, "50,65");

    cr_assert_eq(tetris->width, 65, "%i\n", tetris->width);
    cr_assert_eq(tetris->height, 50);
    cr_assert_eq(res, SUCCESS);
}

Test(set_size, arg1_false)
{
    tetris_t *tetris = init_tetris();
    int res = set_size(tetris, "a,65");

    cr_assert_eq(tetris->width, 10);
    cr_assert_eq(tetris->height, 20);
    cr_assert_eq(res, ERROR);
}

Test(set_size, arg2_false)
{
    tetris_t *tetris = init_tetris();
    int res = set_size(tetris, "10,d");

    cr_assert_eq(tetris->width, 10);
    cr_assert_eq(tetris->height, 20);
    cr_assert_eq(res, ERROR);
}