/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Iol
*/

#include "include.h"

infos_t *new_infos(void)
{
    infos_t *infos = calloc(1, sizeof(infos_t));

    infos->head = new_tophead();
    infos->processes = NULL;
    return infos;
}
