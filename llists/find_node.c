/*
** EPITECH PROJECT, 2025
** Lib_llists
** File description:
** Returns the first node containing data equal to the reference data.
*/

#include "llists.h"

llist_t *find_node(llist_t *node, void const *ref,
    int (*cmp_fct)(void const *, void const *))
{
    while (node) {
        if (cmp_fct(node->data, ref) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
