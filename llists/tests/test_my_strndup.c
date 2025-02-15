/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(my_strndup, failing_malloc)
{
    cr_assert(my_strndup("fail", 2222222222) == NULL);
}
