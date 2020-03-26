/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** read_tetrimino
*/

#include "tetris.h"

void load_first_line(tetrimino_t *tetri, char *line)
{
    char **array = NULL;

    if (line == NULL)
        return;
    array = my_str_to_word_array(line, ' ');
}

void file_to_tetrimino(tetrimino_t *t_list, char *fpath)
{
    int fd = open(fpath, O_RDONLY);
    char *line = NULL;
    size_t n = NULL;
    tetrimino_t *tetrimino = init_tetrimino();

    if (fd == -1)
        return;
    getline(&line, &n, fd);
    if (line != NULL)
        free(line);
    my_printf("reading %s\n", fpath);
}

void read_tetriminos(tetrimino_t *t_list)
{
    char **files = get_tetriminos_array();
    int fpath_len = 0;
    char *fpath = NULL;

    for (int i = 0; files[i] != NULL; i++) {
        fpath_len = my_strlen(T_DIR) + my_strlen(files[i]) + 1;
        fpath = malloc(fpath_len * sizeof(char));
        fpath = my_strcpy(fpath, T_DIR);
        fpath = my_strcat(fpath, "/");
        fpath = my_strcat(fpath, files[i]);
        if (access(fpath, R_OK) == 0)
            file_to_tetrimino(t_list, fpath);
        free(fpath);
    }
}