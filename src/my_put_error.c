/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** my_put_error
*/

#include <unistd.h>

void my_error_putchar(char c)
{
    write(2, &c, 1);
}

void my_put_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_error_putchar(str[i]);
        i++;
    }
}
