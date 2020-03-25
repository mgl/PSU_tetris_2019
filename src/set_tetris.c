/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** set_tetris
*/

#include "tetris.h"
#include "my.h"

int set_level(tetris_t *tetris, char *level)
{
    if (my_str_isnum(level)) {
        tetris->level = my_getnbr(level);
        return (SUCCESS);
    } else {
        return (ERROR);
    }
}

int set_size(tetris_t *tetris, char *arg)
{
    char **size = my_str_to_word_array(arg, ',');

    if (my_str_isnum(size[0]) && my_str_isnum(size[1])) {
        tetris->height = my_getnbr(size[0]);
        tetris->width = my_getnbr(size[1]);
        return (SUCCESS);
    } else {
        return (ERROR);
    }
}

int set_next(tetris_t *tetris, char *arg)
{
    if (my_strcmp(arg, "true") == 0) {
        tetris->next = true;
        return (SUCCESS);
    } else if (my_strcmp(arg, "false") == 0) {
        tetris->next = false;
        return (SUCCESS);
    } else {
        return (ERROR);
    }
}