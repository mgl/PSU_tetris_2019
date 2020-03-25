/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_keys
*/

#include "tetris.h"

int set_keys(tetris_t *tetris, char *arg, int opt)
{
    switch (opt) {
    case 'l':
        tetris->k_left = arg[0];
        break;
    case 'r':
        tetris->k_right = arg[0];
        break;
    case 't':
        tetris->k_turn = arg[0];
        break;
    case 'd':
        tetris->k_drop = arg[0];
        break;
    case 'q':
        tetris->k_quit = arg[0];
        break;
    case 'p':
        tetris->k_pause = arg[0];
        break;
    default:
        return (ERROR);
        break;
    }
    return (SUCCESS);
}