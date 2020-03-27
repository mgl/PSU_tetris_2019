/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#include "tetris.h"
#include "usage.h"

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
    mvwprintw(win, y, x, "%s", string);
    wattroff(win, COLOR_PAIR(1));
    refresh();
}

void diplay_name(void)
{
    attron(COLOR_PAIR(2));
    mvwprintw(stdscr, 1, 0, "%s", NAME);
    attroff(COLOR_PAIR(2));
}