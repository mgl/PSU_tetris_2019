/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include "tetris.h"

int game(tetris_t *tetris)
{
    int key;

    initscr();
    keypad(stdscr, true);
    curs_set(0);
    clear();
    box(stdscr, 0, 0);
    refresh();
    endwin();
    return (0);
}