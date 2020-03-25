/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino
*/

#include "tetris.h"

tetrimino_t *init_tetrimino(void)
{
    tetrimino_t *tetrimino = malloc(sizeof(tetrimino_t));

    if (tetrimino != NULL) {
        tetrimino->array = NULL;
        tetrimino->name = NULL;
        tetrimino->color = 7;
        tetrimino->height = 0;
        tetrimino->width = 0;
        tetrimino->next = NULL;
    }
    return (tetrimino);
}

void add_tetrimino(tetrimino_t *t_list, tetrimino_t *to_add)
{
    tetrimino_t *tmp = t_list;

    if (t_list == NULL) {
        t_list = to_add;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = to_add;
}

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void free_t_list(tetrimino_t *t_list)
{
    tetrimino_t *next = t_list->next;

    if (t_list == NULL)
        return;
    while (t_list != NULL) {
        next = t_list->next;
        free_array(t_list->array);
        free(t_list);
        t_list = next;
    }
}

int get_t_list_size(tetrimino_t *t_list)
{
    int size = 0;
    tetrimino_t *tmp = t_list;

    if (t_list == NULL)
        return (0);
    while (tmp->next != NULL) {
        size++;
        tmp = tmp->next;
    }
    return (size);
}