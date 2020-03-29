/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** exit
*/

#include "tetris.h"

void quit(game_t *game)
{
    write_new_hight_score(game);
    delwin(game->win->info);
    delwin(game->win->next);
    delwin(game->win->tetris);
    endwin();
}