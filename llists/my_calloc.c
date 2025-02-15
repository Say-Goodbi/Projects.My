/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Calloc function
*/

#include "llists.h"

void *my_calloc(size_t amount, size_t size)
{
    void *ptr = malloc(size * amount);

    if (ptr == NULL)
        return NULL;
    my_memset(ptr, 0, (size) * amount);
    return ptr;
}
