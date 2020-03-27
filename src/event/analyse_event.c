/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** analyse_event
*/

#include "tetris.h"

int event_quit(tetris_t *tetris, int key)
{
    if (key == tetris->k_quit) {
        return (true);
    } else {
        return (false);
    }
}

void analyse_event(game_t *game, tetris_t *tetris, int key)
{
    // if (event_quit(tet))
}