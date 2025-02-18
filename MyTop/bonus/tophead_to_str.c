/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Tophead_to_str
*/

#include "include.h"

char *tophead_to_str(tophead_t *head)
{
    char *str = calloc(500, 1);
    tasks_t *ta = head->tasks;

    sprintf(str, "top - %s  %s  %s", head->time, head->user, head->loadavg);
    free(head->time);
    free(head->user);
    free(head->loadavg);
    sprintf(str + strlen(str), "\nTasks:%4d total,%4d running,",
        ta->total, ta->run);
    sprintf(str + strlen(str), "%4d sleeping,%4d stopped,%4d zombie",
        ta->sleep, ta->stop, ta->zombie);
    sprintf(str + strlen(str), "%s", head->cpus);
    sprintf(str + strlen(str), "%s", head->mem);
    sprintf(str + strlen(str), "%s", head->swap);
    free(head->cpus);
    free(head->tasks);
    free(head->swap);
    return str;
}
