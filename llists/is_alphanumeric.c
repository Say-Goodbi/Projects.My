/*
** EPITECH PROJECT, 2025
** Llists
** File description:
** Var names
*/

#include "llists.h"

bool is_alpha_char(char c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

bool is_alphanumeric_char(char c)
{
    if (is_alpha_char(c))
        return true;
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool is_alphanumeric(char *str)
{
    for (; *str != 0; str++) {
        if (is_alphanumeric_char(*str) == false)
            return false;
    }
    return true;
}
