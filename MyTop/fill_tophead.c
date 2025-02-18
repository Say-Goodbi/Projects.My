/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Fills all attributes of the given process.
*/

#include "include.h"

void fill_tophead(tophead_t *tophead)
{
    tophead->time = my_getuptime();
    tophead->user = my_getusers();
    tophead->loadavg = my_getloadavg();
    tophead->tasks = gettasks();
    tophead->cpus = my_getcpus();
    tophead->mem = my_getmem();
    tophead->swap = my_getswap();
}
