/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_arg
*/

#include "tetris.h"
#include "usage.h"
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

static struct option long_option[] = {
    {"help", 0, 0, 'h'},
    {"level", 1, 0, 'L'},
    {"key-left", 1, 0, 'l'},
    {"key-right", 1, 0, 'r'},
    {"key-turn", 1, 0, 't'},
    {"key-drop", 1, 0, 'd'},
    {"key-quit", 1, 0, 'q'},
    {"key-pause", 1, 0, 'p'},
    {"map-size", 1, 0, 'm'},
    {"without-next", 1, 0, 'w'},
    {"debug", 0, 0, 'D'}
};

static int no_arg(int opt, tetris_t *tetris)
{
    if (opt == 'D') {
        return (set_debug(tetris));
    } else if (opt == 'h') {
        printf("%s", USAGE);
        return (SUCCESS);
    } else {
        return (ERROR);
    }
}

static int set_param(int opt, tetris_t *tetris, char *optarg)
{
    if (opt == 'L') {
        return (set_level(tetris, optarg));
    } else if (opt == 'm') {
        return (set_size(tetris, optarg));
    } else {
        return (set_next(tetris, optarg));
    }
}

int get_arg(int ac, char **av, tetris_t *tetris)
{
    int opt = 0;
    int option_index = 0;
    int res = 0;

    if (!tetris)
        return (ERROR);
    while ((opt = getopt_long(ac, av, OPTSTRING, long_option, &option_index)) \
!= -1) {
        if (opt == 'l' || opt == 'r' || opt == 't' || opt == 'd' || opt == 'q' \
|| opt == 'p') {
            res = set_keys(tetris, optarg, opt);
        }else if (opt == 'L' || opt == 'w' || opt == 'm') {
            res = set_param(opt, tetris, optarg);
        } else {
            res = no_arg(opt, tetris);
        }
    }
    return res;
}