/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main
*/

#include "tetris.h"

int main(int ac, char **av)
{
    tetrimino_t *t_list = init_tetrimino();

    read_tetriminos(t_list);
    return (0);
}