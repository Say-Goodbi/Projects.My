/*
** EPITECH PROJECT, 2025
** LibFree
** File description:
** Freeing
*/

#include "llists.h"

void mfree_list(llist_t *subfrees, void **target_ptr)
{
    mfree_t sfree = subfrees->next ? ((mfree_t)(subfrees->data)) : &mfree_dft;
    llist_t *tmp = (llist_t *)(*target_ptr);
    llist_t *garbage = NULL;

    while (tmp) {
        sfree(subfrees->next, &tmp->data);
        garbage = tmp;
        tmp = tmp->next;
        free(garbage);
    }
    *target_ptr = NULL;
}
