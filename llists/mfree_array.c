/*
** EPITECH PROJECT, 2025
** LibFree
** File description:
** Freeing
*/

#include "llists.h"

void mfree_array(llist_t *subfrees, void *target)
{
    mfree_t sfree = subfrees->next ? ((mfree_t)(subfrees->data)) : &mfree_dft;
    void **arr = (void **)target;

    if (!target)
        return;
    while (*arr) {
        sfree(subfrees->next, *arr);
        arr++;
    }
    free(target);
}
