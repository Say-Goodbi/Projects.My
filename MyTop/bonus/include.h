/*
** EPITECH PROJECT, 2024
** Bootstrap my_top
** File description:
** Header
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <curses.h>
    #include <time.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <stddef.h>
    #include <utmp.h>
    #include <pwd.h>
    #include <unistd.h>
    #include <signal.h>
    #include "structs.h"
typedef struct window_context {
    WINDOW *full;
    WINDOW *top;
    WINDOW *box;
    WINDOW *bottom;
    int height;
    int width;
    int offset;
    int line;
} window_t;

char *jump_to(char *string, char delimiter, int times);
tophead_t *new_tophead(void);
void fill_tophead(tophead_t *tophead);
char *tophead_to_str(tophead_t *head);
char *my_getuptime(void);
char *my_getloadavg(void);
tasks_t *gettasks(void);
char *my_getcpus(void);
char *my_getmem(void);
char *my_getswap(void);
char *my_getusers(void);
window_t *new_win(void);
infos_t *new_infos(void);
llist_t *fill_processes(llist_t *processes);
llist_t *sorted_insert(llist_t *list, void *data,
    int (*comp)(llist_t *p1, llist_t *p2));
int cpucmp(llist_t *p1, llist_t *p2);
process_t *get_process(char *pid, glob_info_t *glob);
void wprint_processes(window_t *win, llist_t *processes, char *usr);
void destroy_list(llist_t *list);
char *getcomm(char *statline);
args_t *args_parse(int ac, char **av);
void kill_a_proc(window_t *win, int pid, int sig);
#endif
