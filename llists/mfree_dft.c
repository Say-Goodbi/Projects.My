/*
** EPITECH PROJECT, 2025
** LibFree
** File description:
** Freeing
*/

#include "llists.h"

void mfree_dft(llist_t *subfree, void *target)
{
    (void)subfree;
    if (target)
        free(target);
}
