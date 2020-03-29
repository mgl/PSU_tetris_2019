/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#include "tetris.h"

void print_in_middle(WINDOW *win, int width, char *string)
{
    int length;
    int x;
    int y;
    float temp;

    if (win == NULL)
        win = stdscr;
    getyx(win, y, x);
    length = my_strlen(string);
    temp = (width - length)/ 2;
    x += (int)temp;
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, y + 1, x, "%s", string);
    wattroff(win, COLOR_PAIR(1));
    refresh();
}

void display_next(game_t *game, tetris_t *tetris)
{
    box(game->win->next, 0, 0);
    print_in_middle(game->win->next, 10, "next");
    mvwaddch(game->win->next, 2, 0, ACS_LTEE);
    mvwhline(game->win->next, 2, 1, ACS_HLINE, 8);
    mvwaddch(game->win->next, 2, 9, ACS_RTEE);
}

void display_tetris(game_t *game, tetris_t *tetris)
{
    box(game->win->tetris, 0, 0);
}

void diplay_name(void)
{
    attron(COLOR_PAIR(2));
    mvwprintw(stdscr, 1, 0, "%s", NAME);
    attroff(COLOR_PAIR(2));
}

void display(game_t *game, tetris_t *tetris)
{
    diplay_name();
    display_tetris(game, tetris);
    display_next(game, tetris);
    display_info(game, tetris);
}