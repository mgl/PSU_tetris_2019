/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_compare
*/

#include "tetris.h"
#include <criterion/criterion.h>

Test(compare, true)
{
    int array[5] = {5, 6, 8, 3, 7};
    int res = compare(8, array);

    cr_assert_eq(res, true);
}

Test(compare, false)
{
    int array[5] = {5, 6, 8, 3, 8};
    int res = compare(8, array);

    cr_assert_eq(res, false);
}