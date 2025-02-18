/*
** EPITECH PROJECT, 2024
** Bootstrap my_top
** File description:
** Opens a Terminal User Interface
*/

#include "include.h"

static char *take_input(window_t *my_win)
{
    char *input = calloc(256, 1);

    if (input == NULL)
        return NULL;
    echo();
    nodelay(my_win->box, false);
    cbreak();
    wmove(my_win->box, 0, 37);
    wscanw(my_win->box, "%s", input);
    nodelay(my_win->box, true);
    noecho();
    return input;
}

void kpressed(int ch, window_t *my_win)
{
    char *entered = NULL;
    int pid = 1;
    int sig = 0;

    if (ch == 107) {
        mvwprintw(my_win->box, 0, 0,
            "PID to signal/kill [default pid = %d] ", pid);
        entered = take_input(my_win);
        if (entered != NULL) {
            pid = atoi(entered);
            wclear(my_win->box);
            mvwprintw(my_win->box, 0, 0,
                "Send pid %d signal [15/sigterm] ", 1);
            entered = take_input(my_win);
        }
        if (entered != NULL) {
            sig = atoi(entered);
            kill_a_proc(my_win, pid, sig);
        }
    }
}

void fill_and_print(window_t *my_win, infos_t *infos, args_t *opts)
{
    char *topstr = NULL;

    wclear(my_win->bottom);
    wclear(my_win->top);
    fill_tophead(infos->head);
    infos->processes = fill_processes(infos->processes);
    wprint_processes(my_win, infos->processes, opts->U);
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

void endtop(infos_t *infos, window_t *my_win, args_t *opts)
{
    endwin();
    free(my_win);
    free(infos);
    if (opts->U)
        free(opts->U);
    free(opts);
}

int main(int argc, char **argv)
{
    window_t *my_win = new_win();
    args_t *opts = args_parse(argc, argv);
    time_t clock = opts ? time(NULL) - opts->d : 0;
    int ch = -1;
    infos_t *infos = new_infos();

    if (opts == NULL)
        return 84;
    fill_and_print(my_win, infos, opts);
    do {
        ch = wgetch(my_win->box);
        noecho();
        kpressed(ch, my_win);
        if (time(NULL) - clock > opts->d - 1) {
            fill_and_print(my_win, infos, opts);
            clock = time(NULL);
            opts->n = opts->n > 0 ? opts->n - 1 : -1;
        }
    } while (ch != 113 && opts->n != 0);
    endtop(infos, my_win, opts);
}
