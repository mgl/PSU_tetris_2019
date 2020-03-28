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

Test(get_arg, arg_invalid)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 2;
    char *av[] = {"./tetris", "-k"};

    cr_assert_eq(get_arg(ac, av, tetris), ERROR);
}

Test(get_arg, h, .init=cr_redirect_stdout)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 2;
    char *av[] = {"./tetris", "-h"};

    get_arg(ac, av, tetris);
    fflush(stdout);
    cr_assert_stdout_eq_str(USAGE, "%s", stdout);
    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
}

Test(get_arg, help, .init=cr_redirect_stdout)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 2;
    char *av[] = {"./tetris", "-h"};

    get_arg(ac, av, tetris);
    fflush(stdout);
    cr_assert_stdout_eq_str(USAGE, "%s", stdout);
    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);

}

Test(get_arg, L)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 3;
    char *av[] = {"./tetris", "-L", "10"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->level, 10);
}

Test(get_arg, level)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 3;
    char *av[] = {"./tetris", "--level", "10"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->level, 10);
}

Test(get_arg, D)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 2;
    char *av[] = {"./tetris", "-D"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->debug, true);
}

Test(get_arg, debug)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 2;
    char *av[] = {"./tetris", "--debug"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->debug, true);
}

Test(get_arg, w)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 3;
    char *av[] = {"./tetris", "-w", "true"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->next, true);
}

Test(get_arg, without_next)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 3;
    char *av[] = {"./tetris", "--without-next", "true"};

    get_arg(ac, av, tetris);
    cr_assert_eq(tetris->next, true);
}

Test(get_arg, size_map)
{
    tetris_t *tetris = init_tetris(NULL);
    int ac = 3;
    char *av[] = {"./tetris", "--map-size", "25,30"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->height, 25);
    cr_assert_eq(tetris->width, 30);
}

Test(get_arg, le)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "-l", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_left, 'y');
}

Test(get_arg, key_left)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "--key-left", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_left, 'y');
}

Test(get_arg, r)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "-r", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_right, 'y');
}

Test(get_arg, t)
{
   tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "-t", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_turn, 'y');
}

Test(get_arg, d)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "-d", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_drop, 'y');
}

Test(get_arg, q)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "-q", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_quit, 'y');
}

Test(get_arg, p)
{
    tetrimino_t *list = NULL;
    tetris_t *tetris = init_tetris(list);
    int ac = 3;
    char *av[] = {"./tetris", "-p", "y"};

    cr_assert_eq(get_arg(ac, av, tetris), SUCCESS);
    cr_assert_eq(tetris->k_pause, 'y', "key: %c\natt: %c", tetris->k_pause, \
    'y');
}