/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Returns an allocated but empty tophead.
*/

#include "include.h"

tophead_t *new_tophead(void)
{
    tophead_t *tophead = calloc(1, sizeof(tophead_t));

    return tophead;
}
