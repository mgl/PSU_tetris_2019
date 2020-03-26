/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_arg
*/

#include "tetris.h"
char *convert_int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = nb;
    str[1] = '\0';
    return (str);
}

char *transform_key(int key)
{
    switch (key) {
    case ' ':
        return ("(space)");
    case KEY_DOWN:
        return ("arrow down");
    case KEY_UP:
        return ("arrow up");
    case KEY_RIGHT:
        return ("arrow right");
    case KEY_LEFT:
        return ("arrow left");
    default:
        return (convert_int_to_str(key));
    }
}

char *transform_next(int next)
{
    if (next == false) {
        return ("yes");
    } else {
        return ("no");
    }
}

debug_arg_t *set_debug_arg(tetris_t *tetris)
{
    debug_arg_t *debug = malloc(sizeof(debug_arg_t));

    debug->k_drop = transform_key(tetris->k_drop);
    debug->k_left = transform_key(tetris->k_left);
    debug->k_pause = transform_key(tetris->k_pause);
    debug->k_quit = transform_key(tetris->k_quit);
    debug->k_right = transform_key(tetris->k_right);
    debug->k_turn = transform_key(tetris->k_turn);
    debug->next = transform_next(tetris->next);
    debug->level = tetris->level;
    debug->size[0] = tetris->height;
    debug->size[1] = tetris->width;
    return (debug);
}

int arg_debug(tetris_t *tetris)
{
    debug_arg_t *debug = set_debug_arg(tetris);

    my_printf("*** DEBUG MODE ***\n\
Key Left :  %s\n\
Key Right :  %s\n\
Key Turn :  %s\n\
Key Drop :  %s\n\
Key Quit :  %s\n\
Key Pause :  %s\n\
Next :  %s\n\
Level :  %i\n\
Size :  %i*%i\n\
", debug->k_left, debug->k_right, debug->k_turn, debug->k_drop, \
    debug->k_quit, debug->k_pause, debug->next, \
    debug->level, debug->size[0], debug->size[1]);
    return (0);
}