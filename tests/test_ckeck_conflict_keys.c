/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_ckeck_conflict_key
*/

#include "tetris.h"
#include <criterion/criterion.h>

Test(check_conflict_keys, true)
{
    tetris_t *tetris = init_tetris(NULL);

    cr_assert_eq(check_conflict_keys(tetris), true);
}

Test(check_conflict_keys, false)
{
    tetris_t *tetris = init_tetris(NULL);

    tetris->k_quit = 'p';
    cr_assert_eq(check_conflict_keys(tetris), false);
}