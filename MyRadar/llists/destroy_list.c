/*
** EPITECH PROJECT, 2024
** organized
** File description:
** Deallocates a linked_list structure.
*/

#include "llists.h"

void destroy_list(llist_t *list)
{
    if (list == NULL)
        return;
    if (list->next == NULL) {
        free(list);
        return;
    }
    destroy_list(list->next);
    free(list);
}
