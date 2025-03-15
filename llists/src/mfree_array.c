/*
** EPITECH PROJECT, 2025
** LibFree
** File description:
** Freeing
*/

#include "llists.h"

void mfree_array(llist_t *subfrees, void **target_ptr)
{
    mfree_t sfree = subfrees->next ? ((mfree_t)(subfrees->data)) : &mfree_dft;
    void **arr = (void **)(*target_ptr);

    if (!arr)
        return;
    while (*arr) {
        sfree(subfrees->next, arr);
        arr++;
    }
    mfree_dft(NULL, target_ptr);
}
