/*
** EPITECH PROJECT, 2025
** FreeF
** File description:
** FREEEEE
*/

#include "llists.h"

const fflag_t freef_defaults[] = {
    {&mfree_dft, "f"},
    {&mfree_array, "a"},
    {&mfree_list, "l"},
    {0}
};

llist_t **freeflags_get(void)
{
    static llist_t *freeflags = NULL;
    fflag_t *flag = NULL;

    if (freeflags)
        return &freeflags;
    for (int i = 0; freef_defaults[i].name; i++) {
        flag = my_calloc(1, sizeof(fflag_t));
        if (!flag)
            return &freeflags;
        flag->name = my_strdup(freef_defaults[i].name);
        if (!flag->name)
            return &freeflags;
        flag->fct = freef_defaults[i].fct;
        push_to_list(&freeflags, flag);
    }
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
