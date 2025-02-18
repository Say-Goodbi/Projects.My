/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Compares processes by cpu%
*/

#include "include.h"

int cpucmp(llist_t *p1, llist_t *p2)
{
    process_t *proc1 = ((process_t *)p1->data);
    process_t *proc2 = ((process_t *)p2->data);

    if (proc1 == NULL)
        return 0;
    if (proc2 == NULL)
        return 1;
    if ((int)(proc1->cpu * 10) == (int)(proc2->cpu * 10)) {
        return atoi(proc2->pid) - atoi(proc1->pid);
    }
    if (proc1->cpu > proc2->cpu)
        return 1;
    else
        return 0;
}
