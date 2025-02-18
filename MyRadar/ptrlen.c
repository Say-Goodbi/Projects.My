/*
** EPITECH PROJECT, 2025
** My radar
** File description:
** O
*/

#include "myradar.h"

int ptrlen(char **array)
{
    int i = 0;

    if (array == NULL)
        return 0;
    while (array[i] != NULL)
        i++;
    return i;
}
