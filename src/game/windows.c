/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** windows
*/

#include "tetris.h"

windows_t *create_windows(tetris_t *tetris)
{
    windows_t *windows = malloc(sizeof(windows_t));

    windows->info = newwin(12, 30, 11, 1);
    windows->next = newwin(7, 10, 1, 36 + tetris->width + 2);
    windows->tetris = newwin(tetris->height + 2, tetris->width + 2, 1, 33);

    return (windows);
}

int check_term_size(tetris_t *tetris)
{
    int height_min = 13;

    if (tetris->height > height_min)
        height_min = tetris->height;
    if (COLS > (48 + tetris->width) && LINES > height_min) {
        return (true);
    } else {
        return (false);
    }
}

void f_refresh(windows_t *win)
{
    wrefresh(stdscr);
    wrefresh(win->tetris);
    wrefresh(win->next);
    wrefresh(win->info);
}