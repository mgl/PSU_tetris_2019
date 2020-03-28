/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "my.h"
#include "usage.h"
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

#define T_DIR ("tetriminos")
#define OPTSTRING "hL:l:r:t:d:q:p:w:D"
#define ERROR 84
#define SUCCESS 0

typedef struct debug_arg_s {
    char *k_left;
    char *k_right;
    char *k_turn;
    char *k_drop;
    char *k_quit;
    char *k_pause;
    char *next;
    int level;
    int size[2];
} debug_arg_t;

typedef struct tetrimino_s {
    int width;
    int height;
    int color;
    char *name;
    char **array;
    int error;
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

typedef struct windows_s {
    WINDOW *tetris;
    WINDOW *next;
    WINDOW *info;
} windows_t;

typedef struct game_s {
    windows_t *win;
    int score;
    int level;
    int lines;
    int hight_score;
    clock_t clock;
} game_t;

/* tetris.c */

int tetris(int ac, char **av);

/* tetrimino.c */

tetrimino_t *init_tetrimino(void);
void add_tetrimino(tetrimino_t *t_list, tetrimino_t *to_add);
void free_array(char **array);
void free_t_list(tetrimino_t *t_list);
int get_t_list_size(tetrimino_t *t_list);
void free_tetrimino(tetrimino_t *tetri);

/* tetrimino_debug.c */

void debug_t_list(tetrimino_t *t_list);
void debug_tetrimino(tetrimino_t *tetrimino);

/* sort_array.c */

void sort_files(char **files, int size);
void set_backline(char *str);

/* open_dir.c */

char **get_tetriminos_array(void);
int get_file_size(char *fpath);
char *get_file_name(char *fpath);

/* read_tetrimino.c */

void read_tetriminos(tetrimino_t *t_list);
int file_to_tetrimino(tetrimino_t *t_list, char *file, char *name);

/* init_tetris.c */

tetris_t *init_tetris(tetrimino_t *t_list);

/* paramètre */

int get_arg(int ac, char **av, tetris_t *tetris);
int set_next(tetris_t *tetris, char *arg);
int set_size(tetris_t *tetris, char *arg);
int set_level(tetris_t *tetris, char *level);
int set_debug(tetris_t *tetris);
int set_keys(tetris_t *tetris, char *arg, int opt);
int compare(int comp, int *array);
int check_conflict_keys(tetris_t *tetris);

/* debug arg */

int arg_debug(tetris_t *tetris);

/* game */

int game(tetris_t *tetris);
int get_score(void);
void new_hight_score(game_t *game);
int write_new_hight_score(game_t *game);
void quit(game_t *game);
int count_char_line(game_t *game, tetris_t *tetris);


/* display */

void print_in_middle(WINDOW *win, int width, char *string);
void diplay_name(void);
windows_t *create_windows(tetris_t *tetris);
int check_term_size(tetris_t *tetris, int cols);
void f_refresh(windows_t *win);
void display_info(game_t *game, tetris_t *tetris);
void display_next(game_t *game, tetris_t *tetris);
void display_tetris(game_t *game, tetris_t *tetris);
void display(game_t *game, tetris_t *tetris);

/* event */

void analyse_event(game_t *game, tetris_t *tetris, int key);
int event_quit(tetris_t *tetris, int key);


/* tools */

void my_put_error(char *str);
char *nbr_to_str(int nbr);

#endif /* !TETRIS_H_ */
