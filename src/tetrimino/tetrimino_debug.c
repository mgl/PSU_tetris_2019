/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_debug
*/

#include "tetris.h"

void print_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        my_printf("%s\n", array[i]);
}

void debug_tetrimino(tetrimino_t *tetrimino)
{
    if (tetrimino == NULL)
        return;
    if (tetrimino->array == NULL || tetrimino->name == NULL)
        return;
    my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n", \
    tetrimino->name, tetrimino->width, tetrimino->height, tetrimino->color);
    print_array(tetrimino->array);
}

void debug_t_list(tetrimino_t *t_list)
{
    tetrimino_t *tmp = t_list;

    my_printf("Tetriminos: %d\n", get_t_list_size(t_list));
    if (t_list == NULL)
        return;
    while (tmp->next != NULL) {
        debug_tetrimino(tmp);
        tmp = tmp->next;
    }
}