/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Kills a processus from a given PID and sig
*/

#include "include.h"

void kill_a_proc(window_t *win, int pid, int sig)
{
    int res = 0;

    sig = sig > 0 ? sig : 100;
    res = kill(pid, sig);
    wclear(win->box);
    if (res == -1) {
        attron(A_REVERSE);
        mvwprintw(win->box, 0, 0, "%s", "Invalid signal or PID");
        attroff(A_REVERSE);
    }
}
