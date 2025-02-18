/*
** EPITECH PROJECT, 2025
** Lib
** File description:
** Str to word array
*/

#include "myradar.h"

char **str_to_word_array(char *string, char delimiter)
{
    llist_t *words = NULL;
    char *str = string;
    int s = 0;
    int i = 0;

    if (str == NULL)
        return NULL;
    while (str[i] != 0) {
        while (str[i] != 0 && str[i] != delimiter) {
            i++;
        }
        append_to_list(&words, my_strndup(str + s, i - s));
        while (str[i] != 0 && str[i] == delimiter) {
            i++;
            s = i;
        }
    }
    return (char **)(list_to_array(words));
}
