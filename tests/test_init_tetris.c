/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_init_tetris
*/

#include <criterion/criterion.h>
#include "tetris.h"

Test(init_tetris, true)
{
    tetris_t *tetris = init_tetris();

    if (tetris) {
        cr_assert_eq(tetris->level, 1);
        cr_assert_eq(tetris->k_left, 0404);
        cr_assert_eq(tetris->k_right, 0405);
        cr_assert_eq(tetris->k_turn, 0403);
        cr_assert_eq(tetris->k_drop, 0402);
        cr_assert_eq(tetris->k_quit, 'q');
        cr_assert_eq(tetris->k_pause, 'p');
        cr_assert_eq(tetris->width, 10);
        cr_assert_eq(tetris->next, false);
        cr_assert_eq(tetris->debug, false);
        cr_assert_null(tetris->t_list);
    }
}