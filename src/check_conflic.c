/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** check_conflic
*/

#include "tetris.h"

int compare(int comp, int *array)
{
    int count = 0;

    for (int i = 0; i < 6; i++){
        if (comp == array[i])
            count++;
    }
    if (count > 1) {
        return (false);
    } else {
        return (true);
    }
}

int check_conflict_keys(tetris_t *tetris)
{
    int array[6] = {tetris->k_drop, tetris->k_left, tetris->k_pause, \
tetris->k_quit, tetris->k_right, tetris->k_turn};
    int i = 0;

    for (; i < 6; i++) {
        if (!compare(array[i], array))
            return (false);
    }
    return (true);
}