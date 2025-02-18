/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Function that compares two strings,
** given as arguments.
*/

#include "myradar.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL || s2 == NULL)
        return 1;
    while (s1[i] == s2[i] &&
        s1[i] != '\0' && s2[i] != '\0')
        i++;
    return s1[i] - s2[i];
}
