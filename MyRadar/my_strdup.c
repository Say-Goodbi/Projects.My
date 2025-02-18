/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Duplicates a string.
*/

#include "include.h"

char *my_strdup(char *string)
{
    int len = my_strlen(string);
    char *str = my_calloc(len + 1, sizeof(char));

    if (str == NULL || string == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        str[i] = string[i];
    str[len] = 0;
    return str;
}
