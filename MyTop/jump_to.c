/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Takes a string and returns adress of its next delimiter.
*/

#include "include.h"

char *jump_to(char *string, char delimiter, int times)
{
    int i = 0;

    if (string == NULL) {
        return NULL;
    }
    while (times > 0) {
        while (string[i] != delimiter && string[i] != '\0')
            i++;
        i++;
        if (string[i] == delimiter)
            return jump_to(string + i, delimiter, times);
        times--;
    }
    if (string[i] == ')')
        return jump_to(string + i, delimiter, 1);
    return string + i;
}

/*
char *jump_to(char *string, char delimiter, int times)
{
    int i = 0;
    int parenthesis = 0;

    if (string == NULL || string[0] == 0) {
        return NULL;
    }
    if (times == 0)
        return string;
    while (string[i] != delimiter && string[i] != '\0') {
        if (string[i] == '(')
            parenthesis++;
        if (string[i] == ')')
            parenthesis--;
        i++;
    }
    i++;
    times = parenthesis > 0 ? times : times - 1;
    return jump_to(string + i, delimiter, times);
}
*/
