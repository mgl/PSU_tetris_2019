/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_keys
*/

#include "tetris.h"

int set_keys_part1(tetris_t *tetris, char *arg, int opt)
{
    if (opt == 'l') {
        tetris->k_left = arg[0];
        return (SUCCESS);
    } else if (opt == 'r') {
        tetris->k_right = arg[0];
        return (SUCCESS);
    } else {
        tetris->k_turn = arg[0];
        return (SUCCESS);
    }
}

int set_keys_part2(tetris_t *tetris, char *arg, int opt)
{
    if (opt == 'd') {
        tetris->k_drop = arg[0];
        return (SUCCESS);
    } else if (opt == 'q') {
        tetris->k_quit = arg[0];
        return (SUCCESS);
    } else {
        tetris->k_pause = arg[0];
        return (SUCCESS);
    }
}

int set_keys(tetris_t *tetris, char *arg, int opt)
{

    if (opt == 'l' || opt == 'r' || opt == 't') {
        return (set_keys_part1(tetris, arg, opt));
    } else if (opt == 'd' || opt == 'q' || opt == 'p') {
        return (set_keys_part2(tetris, arg, opt));
    } else {
        return (ERROR);
    }
}