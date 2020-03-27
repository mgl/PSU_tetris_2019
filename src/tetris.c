/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include "tetris.h"

int tetris(int ac, char **av)
{
    tetrimino_t *t_list = init_tetrimino();
    tetris_t *tetris = init_tetris(t_list);

    get_arg(ac, av, tetris);
    read_tetriminos(t_list);
    if (tetris->debug) {
        arg_debug(tetris);
        debug_t_list(t_list);
        my_printf("Press any key to start Tetris\n");
        getchar();
    }
    game(tetris);
    free_t_list(t_list);
    return (0);
}