/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Prints all info about processes into the ncurse win.
*/

#include "include.h"

void wprint_a_process(window_t *win, int line, int offset,
    process_t *process)
{
    if (process != NULL) {
        mvwprintw(win->bottom, line + 1, offset + 1, "%6s ", process->pid);
        mvwprintw(win->bottom, line + 1, offset + 7, " %.8s", process->user);
        mvwprintw(win->bottom, line + 1, offset + 17, "%3s %3ld",
            process->pr, process->ni);
        mvwprintw(win->bottom, line + 1, offset + 25, "%7s %6s",
            process->virt, process->res);
        mvwprintw(win->bottom, line + 1, offset + 39, " %6s %c",
            process->shr, process->state);
        mvwprintw(win->bottom, line + 1, offset + 49, "%5.1f %5.1f",
            process->cpu, process->mem);
        mvwprintw(win->bottom, line + 1, offset + 62, "%s", process->time);
        mvwprintw(win->bottom, line + 1, offset + 70, " %s",
            process->comm);
    }
}

void wprint_processes(window_t *win, llist_t *processes, char *usr)
{
    int offset = win->offset;
    int line = win->line;
    process_t *proc = NULL;

    while (processes && line < 60) {
        proc = (process_t *)processes->data;
        if (usr == NULL || strcmp(usr, proc->user) == 0) {
            wprint_a_process(win, line, offset, proc);
            line++;
        }
        processes = processes->next;
    }
}
