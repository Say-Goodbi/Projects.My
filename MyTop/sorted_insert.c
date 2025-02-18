/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Inserts a linked list structure to the given linked list,
** where the given comparison function places it.
*/

#include "include.h"

llist_t *sorted_insert(llist_t *list, void *data,
    int (*comp)(llist_t *p1, llist_t *p2))
{
    llist_t *new = calloc(1, sizeof(llist_t));

    new->data = data;
    if (list == NULL) {
        return new;
    }
    if (comp(list, new) > 0) {
        free(new);
        list->next = sorted_insert(list->next, data, comp);
        return list;
    } else {
        new->next = list;
        return new;
    }
}
