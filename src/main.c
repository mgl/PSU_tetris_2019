/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main
*/

#include "tetris.h"

int main(int ac, char **av)
{
    tetris_t *tetris = init_tetris();
    get_arg(ac, av, tetris);
    arg_debug(tetris);
    return (0);
}