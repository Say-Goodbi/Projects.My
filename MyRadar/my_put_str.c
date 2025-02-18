/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** putstr
*/

#include "myradar.h"

int my_strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != 0)
        i++;
    return i;
}

void my_put_str(int fd, const char *str)
{
    if (str == NULL)
        return;
    write(fd, str, my_strlen(str));
}
