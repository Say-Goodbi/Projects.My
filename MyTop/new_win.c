/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Creates windows
*/

#include "include.h"

window_t *new_win(void)
{
    window_t *my_win = calloc(1, sizeof(window_t));

    my_win->full = initscr();
    my_win->top = subwin(stdscr, 5, COLS, 0, 0);
    my_win->box = subwin(stdscr, 1, COLS, 5, 0);
    my_win->bottom = subwin(stdscr, LINES - 6, COLS, 6, 0);
    my_win->height = COLS;
    my_win->width = LINES;
    my_win->offset = 0;
    my_win->line = 0;
    nodelay(my_win->full, true);
    nodelay(my_win->top, true);
    nodelay(my_win->box, true);
    nodelay(my_win->bottom, true);
    noecho();
    return my_win;
}
