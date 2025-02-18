/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** Deallocates a linked_list structure.
*/

#include "include.h"

void destroy_process(process_t *process)
{
    if (process != NULL) {
        if (process->user)
            free(process->user);
        free(process->pr);
        free(process->virt);
        free(process->res);
        free(process->shr);
        free(process->time);
        free(process->comm);
        free(process);
    }
}

void destroy_list(llist_t *list)
{
    if (list == NULL)
        return;
    if (list->next == NULL) {
        destroy_process((process_t *)list->data);
        free(list);
        return;
    }
    destroy_list(list->next);
    destroy_process((process_t *)list->data);
    free(list);
}
