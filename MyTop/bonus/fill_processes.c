/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Takes all informations about processes.
*/

#include "include.h"

float uptime(void)
{
    FILE *stream = fopen("/proc/uptime", "r");
    char *buffer = calloc(50, 1);
    float uptime = 0;

    if (buffer == NULL)
        exit(84);
    if (stream != NULL) {
        fgets(buffer, 50, stream);
        fclose(stream);
        uptime = atof(buffer);
    }
    free(buffer);
    return uptime;
}

float totmem(void)
{
    FILE *stream = fopen("/proc/meminfo", "r");
    char *buffer = calloc(50, 1);
    float totmem = 0;

    if (buffer == NULL)
        exit(84);
    if (stream != NULL) {
        fgets(buffer, 50, stream);
        fclose(stream);
        totmem = atof(jump_to(buffer, ' ', 1));
    }
    free(buffer);
    return totmem;
}

llist_t *fill_processes(llist_t *processes)
{
    DIR *dir = opendir("/proc");
    process_t *process = NULL;
    struct dirent *entry = dir != NULL ? readdir(dir) : NULL;
    glob_info_t glob = {uptime(), totmem()};

    while (entry != NULL) {
        if (entry != NULL && atoi(entry->d_name) > 0) {
            process = get_process(entry->d_name, &glob);
            processes = sorted_insert(processes, process, cpucmp);
        }
        entry = readdir(dir);
    }
    if (dir)
        closedir(dir);
    return processes;
}
