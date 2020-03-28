/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** clear_line
*/

#include "tetris.h"

void clear_line(game_t *game, tetris_t *tetris, int line)
{
    mvwhline(game->win->tetris, line, 1, ' ', tetris->width);
}

int count_char_line(game_t *game, tetris_t *tetris)
{
    int i = 0;
    int count = 0;

    for (; i < tetris->width; i++) {
        if (wmove(game->win->tetris, 3, i) == '*')
            count++;
    }
    printf("%i\n", count);
}