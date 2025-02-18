/*
** EPITECH PROJECT, 2024
** Bootstrap my_top
** File description:
** Opens a Terminal User Interface
*/

#include "include.h"

void kpressed(int ch, window_t *my_win)
{
    if (ch == 107) {
        mvwprintw(my_win->box, 0, 0,
            "PID to signal/kill [default pid = %d] ", 1);
        echo();
        nodelay(my_win->box, false);
        do {
            ch = wgetch(my_win->box);
        } while (ch != 10);
        nodelay(my_win->box, true);
        noecho();
    }
}

void fill_and_print(window_t *my_win, infos_t *infos)
{
    char *topstr = NULL;

    clear();
    fill_tophead(infos->head);
    infos->processes = fill_processes(infos->processes);
    wprint_processes(my_win, infos->processes);
    destroy_list(infos->processes);
    infos->processes = NULL;
    topstr = tophead_to_str(infos->head);
    mvwprintw(my_win->top, 0, 0, "%s", topstr);
    attrset(A_REVERSE);
    mvprintw(6, 0, "    PID USER      PR  NI    VIRT    RES    SHR S  %%CPU"
        "  %%MEM     TIME+ COMMAND%*s", COLS - 78, "");
    attrset(A_NORMAL);
    wrefresh(my_win->bottom);
    wrefresh(my_win->top);
    wmove(my_win->box, 0, 0);
}

void endtop(infos_t *infos, window_t *my_win)
{
    endwin();
    free(my_win);
    free(infos);
}

int main(void)
{
    window_t *my_win = new_win();
    int d = 3.0f;
    time_t clock = time(NULL) - d;
    int ch = -1;
    int n = -1;
    infos_t *infos = new_infos();

    fill_and_print(my_win, infos);
    do {
        ch = wgetch(my_win->box);
        noecho();
        kpressed(ch, my_win);
        if (time(NULL) - clock > d - 1) {
            fill_and_print(my_win, infos);
            clock = time(NULL);
            n = n == -1 ? -1 : n - 1;
        }
    } while (ch != 113 && n != 0);
    endtop(infos, my_win);
}
