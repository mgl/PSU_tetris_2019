/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include "tetris.h"

void f_set_color(void)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

}

void f_init(void)
{
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    f_set_color();
}

int game(tetris_t *tetris)
{
    int key;
    windows_t *windows;

    f_init();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    if (check_term_size(tetris, COLS)) {
        windows = create_windows(tetris);
        diplay_name();
        f_refresh(windows);
        while ((key = getch()) != tetris->k_quit) {
        }
        endwin();
        return (0);
    } else {
        endwin();
        return (ERROR);
    }
}

