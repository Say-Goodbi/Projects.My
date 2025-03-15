/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(mfree_list, mfree_list_no_subfree)
{
    llist_t *subfrees = my_calloc(1, sizeof(llist_t));
    llist_t *wl = str_to_word_list("Get off me", "e ");
    void *caca = NULL;

    cr_assert(subfrees != NULL);
    cr_assert(wl != NULL);
    mfree_list(subfrees, &caca);
    mfree_list(subfrees, (void **)&wl);
}
