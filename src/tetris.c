/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include "tetris.h"

int tetris(int ac, char **av)
{
    tetris_t *tetris = init_tetris();
    get_arg(ac, av, tetris);
    return (0);
}