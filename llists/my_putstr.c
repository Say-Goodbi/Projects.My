/*
** EPITECH PROJECT, 2025
** Liblists
** File description:
** Puts string
*/

#include "llists.h"

void my_putstr(char *str)
{
    if (!str)
        return;
    write(1, str, my_strlen(str));
}
