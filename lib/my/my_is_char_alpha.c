/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my_is_char_alpha
*/

#include "my.h"

int my_is_char_alpha(char c, char delim)
{
    return (c != delim && c != ' ' && c != '\t' && c != 0);
}