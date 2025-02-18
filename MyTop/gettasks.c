/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Get tasks.*
*/

#include "include.h"

void status_add(tasks_t *tasks, char status)
{
    switch (status) {
        case 'S':
            tasks->sleep += 1;
            break;
        case 'I':
            tasks->sleep += 1;
            break;
        case 'R':
            tasks->run += 1;
            break;
        case 'Z':
            tasks->zombie += 1;
            break;
        case 'B':
            tasks->stop += 1;
    }
}

void add_task(tasks_t *tasks, char *entryname)
{
    FILE *file = NULL;
    char path[256] = "";
    char *statline = calloc(1, 256);
    char *status = NULL;

    sprintf(path, "/proc/%s/stat", entryname);
    file = fopen(path, "r");
    if (file != NULL) {
        fgets(statline, 256, file);
        status = jump_to(statline, ')', 1);
        tasks->total += 1;
        status_add(tasks, status[1]);
        fclose(file);
    }
    free(statline);
}

tasks_t *gettasks(void)
{
    tasks_t *ta = calloc(1, sizeof(tasks_t));
    DIR *dir = opendir("/proc");
    struct dirent *entry = dir != NULL ? readdir(dir) : NULL;

    while (entry != NULL) {
        if (entry != NULL && atoi(entry->d_name) > 0) {
            add_task(ta, entry->d_name);
        }
        entry = readdir(dir);
    }
    if (dir != NULL)
        closedir(dir);
    return ta;
}
