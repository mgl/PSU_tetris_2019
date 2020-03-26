/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** open_dir
*/

#include "tetris.h"

int get_file_size(char *fpath)
{
    struct stat st;

    if (stat(fpath, &st) == 0)
        return (st.st_size);
    return (-1);
}

void print_triminos(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        my_printf("%s\n", array[i]);
}

char **get_tetriminos_array(void)
{
    DIR* dir = opendir(T_DIR);
    struct dirent *de = NULL;
    int f_count = 0;
    char **files = malloc(2048 * sizeof(char *));
    char *tmp = NULL;

    while ((de = readdir(dir)) != NULL) {
        tmp = my_revstr(my_strdup(de->d_name));
        if (my_strncmp("onimirtet.", tmp, 10) == 0) {
            files[f_count] = my_strdup(de->d_name);
            f_count++;
        }
        free(tmp);
    }
    files[f_count] = NULL;
    sort_files(files, f_count);
    return (files);
}