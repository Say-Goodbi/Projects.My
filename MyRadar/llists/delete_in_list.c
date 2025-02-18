/*
** EPITECH PROJECT, 2024
** bs_organized
** File description:
** Removes all nodes containing data equal to the reference data.
*/

#include "llists.h"

void delete_in_list(llist_t **begin, void const *ref, int (*cmp_fct)())
{
    llist_t **next = (*begin) != NULL ? &(*begin)->next : NULL;

    if (*begin != NULL) {
        if (cmp_fct((*begin)->data, ref) == 0) {
            free(*begin);
            begin = next;
        }
        delete_in_list(next, ref, cmp_fct);
    }
}
