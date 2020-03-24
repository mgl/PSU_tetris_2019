/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** init_tetris
*/

#include "tetris.h"
#include <stdlib.h>

tetris_t *init_tetris(void)
{
    tetris_t *tetris = malloc(sizeof(tetris_t));

    tetris->level = 1;
    tetris->k_left = KEY_LEFT;
    tetris->k_right = KEY_RIGHT;
    tetris->k_turn = KEY_UP;
    tetris->k_drop = KEY_DOWN;
    tetris->k_quit = 'q';
    tetris->k_pause = 'p';
    tetris->width = 10;
    tetris->height = 20;
    tetris->next = false;
    tetris->debug = false;
    tetris->t_list = malloc(sizeof(tetrimino_t));
    if (!tetris->t_list) {
        return (NULL);
    }
    tetris->t_list = NULL;
    return (tetris);
}