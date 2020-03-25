/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <unistd.h>
#include <ncurses.h>
#define OPTSTRING "hL:l:r:t:d:q:w:D"
#define ERROR 84
#define SUCCESS 0

typedef struct tetrimino_s {
    int width;
    int height;
    int color;
    char **array;
    struct tetrimino_s *next;
} tetrimino_t;

typedef struct tetris_s {
    int level;
    int k_left;
    int k_right;
    int k_turn;
    int k_drop;
    int k_quit;
    int k_pause;
    int width;
    int height;
    int next;
    int debug;
    tetrimino_t *t_list;
} tetris_t;

/* tetris.c */

int tetris(int ac, char **av);

/* initialisation */

tetris_t *init_tetris(void);

/* paramètre */

int get_arg(int ac, char **av, tetris_t *tetris);
int set_next(tetris_t *tetris, char *arg);
int set_size(tetris_t *tetris, char *arg);
int set_level(tetris_t *tetris, char *level);

#endif /* !TETRIS_H_ */
