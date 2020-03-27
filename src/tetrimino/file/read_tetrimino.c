/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** read_tetrimino
*/

#include "tetris.h"

int load_first_line(tetrimino_t *tetri, char *line)
{
    char **array = NULL;

    if (line == NULL)
        return (1);
    set_backline(line);
    array = my_str_to_word_array(line, ' ');
    if (array[0] == NULL || !my_str_isnum(array[0]))
        return (1);
    tetri->width = my_atoi(array[0]);
    if (array[1] == NULL || !my_str_isnum(array[1]))
        return (1);
    tetri->height = my_atoi(array[1]);
    if (array[2] == NULL || !my_str_isnum(array[2]) || my_atoi(array[2]) > 7)
        return (1);
    tetri->color = my_atoi(array[2]);
    if (array[3] != NULL)
        return (1);
    return (0);
}

int get_stars_count(char *str)
{
    int i = 0;

    for (; str[i] != '*'; i++)
        if (str[i] == '\0')
            break;
    return (i);
}

int load_array(tetrimino_t *tetrimino, FILE *file)
{
    char **array = malloc(tetrimino->height * sizeof(char *));
    size_t n = 0;

    tetrimino->array = array;
    for (int i = 0; i < tetrimino->height; i++) {
        if (getline(&array[i], &n, file) == -1)
            return (1);
        set_backline(array[i]);
        if (get_stars_count(array[i]) > tetrimino->width)
            return (1);
    }
    array[tetrimino->height] = NULL;
    return (0);
}

int file_to_tetrimino(tetrimino_t *t_list, char *fpath, char *name)
{
    FILE *file = fopen(fpath, "r");
    char *line = NULL;
    tetrimino_t *tetrimino = init_tetrimino();
    size_t n = 0;

    if (file == NULL)
        return (1);
    tetrimino->name = get_file_name(name);
    if (getline(&line, &n, file) == -1)
        return (1);
    if (line != NULL) {
        if (load_first_line(tetrimino, line) == 1) {
            free_tetrimino(tetrimino);
            return (1);
        }
        free(line);
    }
    if (load_array(tetrimino, file) == 1)
        return (1);
    add_tetrimino(t_list, tetrimino);
    return (0);
}

void read_tetriminos(tetrimino_t *t_list)
{
    char **files = get_tetriminos_array();
    int fpath_len = 0;
    char *fpath = NULL;
    tetrimino_t *t_error = NULL;

    for (int i = 0; files[i] != NULL; i++) {
        fpath_len = my_strlen(T_DIR) + my_strlen(files[i]) + 2;
        fpath = malloc(fpath_len * sizeof(char));
        fpath = my_strcpy(fpath, T_DIR);
        fpath = my_strcat(fpath, "/");
        fpath = my_strcat(fpath, files[i]);
        if (access(fpath, R_OK) != 0)
            continue;
        if (file_to_tetrimino(t_list, fpath, files[i]) == 1) {
            t_error = init_tetrimino();
            t_error->error = 1;
            t_error->name = get_file_name(files[i]);
            add_tetrimino(t_list, t_error);
        }
        free(fpath);
    }
}