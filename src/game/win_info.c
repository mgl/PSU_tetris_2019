/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** win_info
*/

#include "tetris.h"

void display_info(tetris_t *tetris, game_t *game)
{
    box(game->win->info, 0, 0);
    print_in_middle(game->win->info, 30, "info");
    mvwprintw(game->win->info, 2, 1, "Hight score:\t1500");
    mvwprintw(game->win->info, 3, 1, "score:      \t%i", game->score);
    mvwprintw(game->win->info, 5, 1, "Lines:      \t%i", game->lines);
    mvwprintw(game->win->info, 6, 1, "Level:      \t%i", game->level);
    mvwprintw(game->win->info, 8, 1, "Timer:      \t%i:%i", \
    game->clock / CLOCKS_PER_SEC, game->clock % CLOCKS_PER_SEC);
}