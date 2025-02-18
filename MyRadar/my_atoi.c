/*
** EPITECH PROJECT, 2024
** Lib
** File description:
** Returns a number, from its given string form.
** Can return -1 if string isn't a positive number.
*/

#include "myradar.h"

int my_atoi(char const *str)
{
    int i = 0;
    int tot = 0;

    if (str == NULL)
        return -1;
    while (str[i] > 47 && str[i] < 58) {
        tot = tot * 10;
        tot += str[i] - 48;
        i++;
    }
    return i > 0 ? tot : -1;
}
