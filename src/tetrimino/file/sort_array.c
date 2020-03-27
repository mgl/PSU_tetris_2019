/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** sort_array
*/

#include "tetris.h"

void set_backline(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    str[i] = '\0';
}

void sort_sublist(char **files, int size, int i)
{
    int j = 0;
    char minStr[4097];
    int min_idx = i;

    my_strcpy(minStr, files[i]);
    for (j = i + 1; j < size; j++) {
        if (my_strcmp(minStr, files[j]) > 0) {
            my_strcpy(minStr, files[j]);
            min_idx = j;
        }
    }
    if (min_idx != i) {
        char temp[4097];
        my_strcpy(temp, files[i]);
        my_strcpy(files[i], files[min_idx]);
        my_strcpy(files[min_idx], temp);
    }
}

void sort_files(char **files, int size)
{
    for (int i = 0; i < size - 1; i++)
        sort_sublist(files, size, i);
}