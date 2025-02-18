/*
** EPITECH PROJECT, 2025
** Lib
** File description:
** L
*/

#include "myradar.h"

char *my_strndup(const char *src, int n)
{
    char *dest = my_calloc(n + 1, sizeof(char));

    if (src == NULL || dest == NULL)
        return NULL;
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
