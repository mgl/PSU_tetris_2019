/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019 [WSL: Ubuntu]
** File description:
** array_utils
*/

#include "tetris.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}