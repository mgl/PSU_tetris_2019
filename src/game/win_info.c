/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** win_info
*/

#include "tetris.h"

void display_info(game_t *game, tetris_t *tetris)
{
    print_in_middle(game->win->info, 30, "info");
    box(game->win->info, 0, 0);
    mvwaddch(game->win->info, 2, 0, ACS_LTEE);
    mvwhline(game->win->info, 2, 1, ACS_HLINE, 28);
    mvwaddch(game->win->info, 2, 29, ACS_RTEE);
    if (game->score > game->hight_score) {
        mvwprintw(game->win->info, 4, 1, "Hight score:\t\t%i", game->score);
    } else {
        mvwprintw(game->win->info, 4, 1, "Hight score:\t\t%i", \
game->hight_score);
    }
    mvwprintw(game->win->info, 5, 1, "score:      \t\t%i", game->score);
    mvwprintw(game->win->info, 7, 1, "Lines:      \t\t%i", game->lines);
    mvwprintw(game->win->info, 8, 1, "Level:      \t\t%i", game->level);
    mvwprintw(game->win->info, 10, 1, "Timer:      \t\t%i", game->clock / \
CLOCKS_PER_SEC);
}