/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_get_arg
*/

#include "tetris.h"
#include "usage.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(get_arg, tetris_NULL)
{
    tetris_t *tetris = NULL;
    int ac = 2;
    char *av[] = {"./tetris", "-h"};
    int res = get_arg(ac, av, tetris);

    cr_assert_eq(res, ERROR);
}

Test(get_arg, arg_invalid, .init=cr_redirect_stdout)
{
    tetris_t *tetris = init_tetris();
    int ac = 2;
    char *av[] = {"./tetris", "-k"};

    get_arg(ac, av, tetris);
    fflush(stdout);
    cr_assert_stdout_eq_str("Error\n");
}

Test(get_arg, h, .init=cr_redirect_stdout)
{
    tetris_t *tetris = init_tetris();
    int ac = 2;
    char *av[] = {"./tetris", "-h"};

    get_arg(ac, av, tetris);
    fflush(stdout);
    cr_assert_stdout_eq_str(USAGE, "%s", stdout);
}

Test(get_arg, help, .init=cr_redirect_stdout)
{
    tetris_t *tetris = init_tetris();
    int ac = 2;
    char *av[] = {"./tetris", "-h"};

    get_arg(ac, av, tetris);
    fflush(stdout);
    cr_assert_stdout_eq_str(USAGE, "%s", stdout);
}

Test(get_arg, L)
{
    tetris_t *tetris = init_tetris();
    int ac = 3;
    char *av[] = {"./tetris", "-L", "10"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->level, 10);
}

Test(get_arg, level)
{
    tetris_t *tetris = init_tetris();
    int ac = 3;
    char *av[] = {"./tetris", "--level", "10"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->level, 10);
}

Test(get_arg, D)
{
    tetris_t *tetris = init_tetris();
    int ac = 2;
    char *av[] = {"./tetris", "-D"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->debug, true);
}

Test(get_arg, debug)
{
    tetris_t *tetris = init_tetris();
    int ac = 2;
    char *av[] = {"./tetris", "--debug"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->debug, true);
}

Test(get_arg, w)
{
    tetris_t *tetris = init_tetris();
    int ac = 3;
    char *av[] = {"./tetris", "-w", "true"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->next, true);
}


Test(get_arg, without_next)
{
    tetris_t *tetris = init_tetris();
    int ac = 3;
    char *av[] = {"./tetris", "--without-next", "true"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->next, true);
}

Test(get_arg, size_map)
{
    tetris_t *tetris = init_tetris();
    int ac = 3;
    char *av[] = {"./tetris", "--map-size", "25,30"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->height, 25);
    cr_assert_eq(tetris->width, 30);
}