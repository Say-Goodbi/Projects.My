/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Takes PID and returns the command
*/

#include "include.h"

char *getcomm(char *statline)
{
    int pid = atoi(statline);
    char *comm = calloc(256, 1);
    char *pathname = calloc(256, 1);
    int res = sprintf(pathname, "/proc/%d/comm", pid);
    FILE *stream = res > 0 && pid > 0 ? fopen(pathname, "r") : NULL;

    if (stream != NULL) {
        fgets(comm, 256, stream);
        fclose(stream);
    }
    if (pathname)
        free(pathname);
    return comm;
}
