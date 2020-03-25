/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_set_next
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(set_next, true)
{
    tetris_t *tetris = init_tetris();
    int res = set_next(tetris, "true");

    cr_assert_eq(tetris->next, true);
    cr_assert_eq(res, SUCCESS);
}

Test(set_next, false)
{
    tetris_t *tetris = init_tetris();
    int res = set_next(tetris, "false");

    cr_assert_eq(tetris->next, false);
    cr_assert_eq(res, SUCCESS);
}

Test(set_next, invalid_arg)
{
    tetris_t *tetris = init_tetris();
    int res = set_next(tetris, "ad");

    cr_assert_eq(tetris->next, false);
    cr_assert_eq(res, ERROR);
}