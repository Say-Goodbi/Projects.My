/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** All structures used for my_top.
*/

#ifndef TOPSTRUCT_H_
    #define TOPSTRUCT_H_
    #include <time.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} llist_t;

typedef struct args_s {
    llist_t *args;
    int argc;
    llist_t *flags;
    int flagc;
} args_t;

typedef struct process_s {
    char *pid;
    char *user;
    char *pr;
    long int ni;
    char *virt;
    char *res;
    char *shr;
    char state;
    float cpu;
    float mem;
    char *time;
    char *comm;
} process_t;

typedef struct glob_info {
    float uptime;
    float totmem;
} glob_info_t;


typedef struct tasks_s {
    int total;
    int run;
    int sleep;
    int stop;
    int zombie;
} tasks_t;

typedef struct cpus_s {
    size_t user;
    size_t nice;
    size_t sys;
    size_t idle;
    size_t iowait;
    size_t irq;
    size_t softirq;
    size_t stolen;
    size_t tot;
} cpus_t;

typedef struct mem_s {
    double total;
    double free;
    double used;
    double cache;
} mem_t;

typedef struct tophead_s {
    char *time;
    char *user;
    char *loadavg;
    tasks_t *tasks;
    char *cpus;
    char *mem;
    char *swap;
} tophead_t;

typedef struct infos_s {
    tophead_t *head;
    llist_t *processes;
} infos_t;
#endif
