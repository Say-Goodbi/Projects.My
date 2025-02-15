/*
** EPITECH PROJECT, 2025
** FreeF
** File description:
** Free everything !
*/

#include "llists.h"

void freef_add(char *name, void (*free_fct)())
{
    fflag_t *ffct = my_calloc(1, sizeof(fflag_t));
    llist_t **freeflags = freeflags_get();
    char *named = NULL;

    if (!ffct || !name || !free_fct)
        return;
    named = my_strdup(name);
    if (!named)
        return;
    ffct->name = named;
    ffct->fct = free_fct;
    push_to_list(freeflags, ffct);
}

void switchfree(void **pfname)
{
    llist_t *freeflags = *freeflags_get();
    llist_t *tmp = freeflags;
    char *flagname = NULL;

    flagname = ((fflag_t *)tmp->data)->name;
    while (tmp && my_strcmp((char *)(*pfname), flagname) != 0) {
        tmp = tmp->next;
        if (tmp)
            flagname = ((fflag_t *)tmp->data)->name;
    }
    free(*pfname);
    if (!tmp)
        *pfname = &mfree_dft;
    else
        *pfname = ((fflag_t *)tmp->data)->fct;
}

void superfree(char *sformat, void *tofree)
{
    llist_t *freenames = NULL;

    if (!tofree)
        return;
    freenames = str_to_word_list(sformat, ":");
    if (!freenames)
        return;
    my_map(freenames, &switchfree);
    append_to_list(&freenames, NULL);
    ((mfree_t)(freenames->data))(freenames->next, tofree);
    destroy_list(freenames, NULL);
}

void freef(char *format, ...)
{
    va_list ap;
    int i = 0;
    char **elems = NULL;

    va_start(ap, format);
    elems = str_to_word_array(format, " ");
    while (elems && *(elems + i)) {
        superfree(elems[i], va_arg(ap, void *));
        free(elems[i]);
        i++;
    }
    if (elems)
        free(elems);
    va_end(ap);
}
