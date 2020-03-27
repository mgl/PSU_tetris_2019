/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** score
*/

#include "tetris.h"

char *nbr_to_str(int nbr)
{
    char *str = NULL;
    int tmp = nbr;
    int len = 0;

    for (len = 0; tmp > 0; len++) {
        tmp = tmp / 10;
    }
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    len--;
    while (len >= 0) {
        str[len] = nbr % 10 + '0';
        nbr = nbr / 10;
        len--;
    }
    return (str);
}

int get_score(void)
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int score = 0;

    stream = fopen("src/hight_score.txt", "r");
    if (stream == NULL) {
        return (ERROR);
    }
    nread = getline(&line, &len, stream);
    if (nread != -1)
        score = my_getnbr(line);
    free(line);
    fclose(stream);
    return (score);
}

int write_new_hight_score(game_t *game)
{
    int fd = open("src/hight_score.txt", O_WRONLY);
    char *hight_score;
    if (game->score > game->hight_score) {
        hight_score = nbr_to_str(game->score);
        write(fd, hight_score, my_strlen(hight_score));
    }
    close(fd);
    return (0);
}