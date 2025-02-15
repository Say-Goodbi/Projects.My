/*
** EPITECH PROJECT, 2025
** FreeF
** File description:
** FREEEEE
*/

#include "llists.h"

llist_t **freeflags_get(void)
{
    static llist_t *freeflags = NULL;
    fflag_t *farr = NULL;
    fflag_t *flist = NULL;
    fflag_t *ffree = NULL;

    if (freeflags)
        return &freeflags;
    farr = my_calloc(1, sizeof(fflag_t));
    flist = my_calloc(1, sizeof(fflag_t));
    ffree = my_calloc(1, sizeof(fflag_t));
    farr->name = my_strdup("a");
    flist->name = my_strdup("l");
    ffree->name = my_strdup("f");
    farr->fct = &mfree_array;
    flist->fct = &mfree_list;
    ffree->fct = &mfree_dft;
    push_to_list(&freeflags, flist);
    push_to_list(&freeflags, farr);
    push_to_list(&freeflags, ffree);
    return &freeflags;
}

void free_a_fflag(void *flag)
{
    if (!flag)
        return;
    free(((fflag_t *)flag)->name);
    free(flag);
}

void freeflags_free(void)
{
    llist_t *freeflags = *freeflags_get();

    destroy_list(freeflags, &free_a_fflag);
}
