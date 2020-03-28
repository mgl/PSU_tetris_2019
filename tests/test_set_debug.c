/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_set_debug
*/

#include "tetris.h"
#include <criterion/criterion.h>

Test(set_debug, true)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int res = set_debug(tetris);

    cr_assert_eq(tetris->debug, true);
    cr_assert_eq(res, SUCCESS);
}