/*
** EPITECH PROJECT, 2024
** bs_organized
** File description:
** push_to_list
*/

#include "llists.h"

void append_to_list(llist_t **begin, void *data)
{
    llist_t *node = malloc(sizeof(llist_t));

    if (node == NULL)
        return;
    node->next = NULL;
    node->data = data;
    while (*begin != NULL) {
        begin = &(*begin)->next;
    }
    *begin = node;
}
