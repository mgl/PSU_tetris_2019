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

void f_init(game_t *game)
{
    initscr();
    start_color();
    cbreak();
    noecho();
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
    game->map = malloc(sizeof(char *) * tetris->height);
    keypad(game->win->tetris, true);
    nodelay(game->win->tetris, true);
    return (game);
}

int game(tetris_t *tetris)
{
    int key;
    game_t *game = NULL;

    f_init(game);
    if (check_term_size(tetris)) {
        game = init_game(tetris);
        while ((key = wgetch(game->win->tetris))!= tetris->k_quit) {
            clear();
            analyse_event(game, tetris, key);
            display(game, tetris);
            sleep(1);
            game->score++;
        }
        quit(game);
        return (0);
    } else {
        endwin();
        my_put_error("Invalid terminal size\n");
        return (ERROR);
    }
}

