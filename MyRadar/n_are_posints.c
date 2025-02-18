/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** ifznifr
*/

#include "myradar.h"

int is_posint(char *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != 0) {
        if (str[i] < 48 || str[i] > 57)
            return -1;
        i++;
    }
    return 0;
}

int n_are_posints(char **word_array, int n)
{
    if (word_array == NULL)
        return -1;
    for (int i = 0; i < n; i++) {
        if (word_array[i] == NULL || is_posint(word_array[i]) != 0)
            return -1;
    }
    return 0;
}
