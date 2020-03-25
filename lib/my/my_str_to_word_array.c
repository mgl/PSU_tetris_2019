/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_isalpha(char c);

int my_show_word_array(char * const *tab);

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

int my_is_char_alpha(char c, char delim);

int count_substr(char const *str, char delim)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (!my_is_char_alpha(str[i], delim)) {
            count++;
        }
    }
    return (count + 1);
}

char *get_first_word(char const *str, char delim)
{
    int i = 0;
    char *word;

    while (my_is_char_alpha(str[i], delim) == 1) {
        i++;
    }
    word = malloc((i + 1) * sizeof(char));
    my_strncpy(word, str, i);
    word[i] = '\0';
    return (word);
}

int get_word_size(char const *str, int i, char delim)
{
    int size = 0;

    while (my_is_char_alpha(str[i + 1], delim) == 1) {
        i++;
        size++;
    }
    return (size);
}

char *get_word(char const *str, int i, char delim)
{
    int size = get_word_size(str, i, delim);
    char *word;

    word = malloc((size + 1) * sizeof(char));
    my_strncpy(word, &(str[i + 1]), size);
    word[size] = '\0';
    return (word);
}

char **my_str_to_word_array(char const *str, char delim)
{
    char **result = malloc((count_substr(str, delim) + 1) * sizeof(char *));
    int count = 0;

    if (str == NULL)
        return (NULL);
    if (my_strlen(get_first_word(str, delim)) != 0) {
        result[count] = get_first_word(str, delim);
        count++;
    }
    for (int i = 0; i < my_strlen(str); i++) {
        if (my_is_char_alpha(str[i], delim) == 0 && \
        get_word_size(str, i, delim) != 0) {
            result[count] = get_word(str, i, delim);
            count++;
        }
    }
    result[count] = 0;
    return (result);
}
