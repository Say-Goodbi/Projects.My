/*
** EPITECH PROJECT, 2024
** bs_organized
** File description:
** truc
*/

#include "llists.h"

void display_list(llist_t *begin, void(*disp_fct)(void *))
{
    if (begin != NULL) {
        disp_fct(begin);
        display_list(begin->next, disp_fct);
    }
}
