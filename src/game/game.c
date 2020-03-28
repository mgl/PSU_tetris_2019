/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include "tetris.h"

void f_set_color(void)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

}

void f_init(void)
{
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    f_set_color();
}

game_t *init_game(tetris_t *tetris)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->win = create_windows(tetris);
    if (!game->win)
        return (NULL);
    game->score = 0;
    game->hight_score = get_score();
    game->level = tetris->level;
    game->lines = 0;
    game->clock = clock();
    return (game);
}

int game(tetris_t *tetris)
{
    int key;
    game_t *game;

    f_init();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    if (check_term_size(tetris, COLS)) {
        game = init_game(tetris);
        nodelay(game->win->tetris, true);
        while ((key =  wgetch(game->win->tetris))!= tetris->k_quit) {
            clear();
            analyse_event(game, tetris, key);
            display(game, tetris);
            f_refresh(game->win);
            sleep(1);
            game->score++;
        }
        write_new_hight_score(game);
        endwin();
        return (0);
    } else {
        quit(game);
        return (ERROR);
    }
}

