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
        {"debub", 0, 0, 'D'}
    };

int get_arg(int ac, char **av, tetris_t *tetris)
{
    int opt = 0;
    int option_index = 0;

    if (tetris)
        return (ERROR);
    while ((opt = getopt_long(ac, av, OPTSTRING, long_option, &option_index)) != -1) {
        switch ((char)opt) {
        case 'h':
            printf("%s\n", USAGE);
            break;
        case 'L':
            set_level(tetris, optarg);
            break;
        case 'l' || 'r' ||'t' || 'd' || 'q' || 'p':
            // set_key(tetris, optarg);
            break;
        case 'm':
            set_size(tetris, optarg);
            break;
        case 'w':
            set_next(tetris, optarg);
            break;
        case 'D':
            tetris->debug = true;
            break;
        default:
            break;
        }
    }
    return 0;
}