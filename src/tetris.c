/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include "tetris.h"

int tetris(int ac, char **av)
{
    //tetrimino_t *t_list = init_tetrimino();
    tetris_t *tetris = init_tetris(NULL);

    get_arg(ac, av, tetris);
    game(tetris);
    return (0);
}