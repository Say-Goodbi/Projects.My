/*
** EPITECH PROJECT, 2025
** SOLOSTUMPER
** File description:
** sort words
*/


#include "llists.h"

void add_to_list(llist_t **list, char *dup)
{
    if (dup)
        append_to_list(list, dup);
}

bool is_in_str(char c, char *str)
{
    if (!str)
        return false;
    for (; *str; str++) {
        if (*str == c)
            return true;
    }
    return false;
}

llist_t *str_to_word_list(char *av, char *seps)
{
    char *str_start = av;
    llist_t *list = NULL;
    int size = 0;
    char *dup = NULL;

    if (av == NULL)
        return NULL;
    while (av[0] != 0) {
        if (is_in_str(av[0], seps)) {
            dup = size > 0 ? my_strndup(str_start, size) : NULL;
            add_to_list(&list, dup);
            str_start = av + 1;
            size = 0;
        } else {
            size++;
        }
        av++;
    }
    dup = size > 0 ? my_strndup(str_start, size) : NULL;
    return add_to_list(&list, dup), list;
}

char **str_to_word_array(char *av, char *seps)
{
    llist_t *wl = str_to_word_list(av, seps);
    char **wa = (char **)list_to_array(wl);

    return wa;
}
