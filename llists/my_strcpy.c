/*
** EPITECH PROJECT, 2025
** LibLists
** File description:
** Cpy for shell
*/

#include "llists.h"

char *my_strcpy(char *dest, char *src)
{
    if (!src)
        return dest;
    for (size_t i = 0; src[i]; i++) {
        dest[i] = src[i];
    }
    return dest;
}
