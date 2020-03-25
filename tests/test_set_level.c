/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_set_level
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(set_level, true_arg)
{
    tetris_t *tetris = init_tetris();
    int res = set_level(tetris, "50");

    cr_assert_eq(tetris->level, 50);
    cr_assert_eq(res, SUCCESS);
}

Test(set_level, false_arg)
{
    tetris_t *tetris = init_tetris();
    int res = set_level(tetris, "ad");

    cr_assert_eq(tetris->level, 1);
    cr_assert_eq(res, SUCCESS);
}