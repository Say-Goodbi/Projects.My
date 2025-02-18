/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** d,kfzvfha
*/

#include "include.h"

static char *getusrname(struct stat *buff)
{
    struct passwd *pwuid = getpwuid(buff->st_uid);
    char *name = strdup(pwuid->pw_name);

    if (strlen(name) > 8)
        name[7] = '+';
    return name;
}

static char *getvsize(long unsigned int vsize, int cap)
{
    char *buffvirt = calloc(20, 1);

    if ((int)vsize > cap - 1)
        sprintf(buffvirt, "%.1fg", (double)vsize / 1024 / 1024);
    else
        sprintf(buffvirt, "%lu", vsize);
    return buffvirt;
}

static char *getshr(char *tmppath)
{
    char *pathname = tmppath != NULL ? strdup(tmppath) : NULL;
    int res = sprintf(pathname + strlen(pathname), "m");
    char *buffer = calloc(256, 1);
    FILE *stream = pathname != NULL ? fopen(pathname, "r") : NULL;
    int shr = 0;

    if (stream != NULL && res > 0) {
        fgets(buffer, 255, stream);
        fclose(stream);
        if (buffer != NULL) {
            shr = atoi(jump_to(buffer, ' ', 2)) * 4;
            free(buffer);
            buffer = getvsize(shr, 1000000);
        }
    }
    free(pathname);
    return buffer;
}

static float getprocmem(char *tmppath, glob_info_t *g)
{
    char *pathname = tmppath != NULL ? strdup(tmppath) : NULL;
    int fres = sprintf(pathname + strlen(pathname), "us");
    char *buffer = calloc(256, 1);
    FILE *stream = pathname != NULL ? fopen(pathname, "r") : NULL;
    int procmem = 0;
    char *vmsize = NULL;
    char *getres = NULL;

    if (buffer != NULL && stream != NULL && fres > 0) {
        do {
            getres = fgets(buffer, 255, stream);
            vmsize = strstr(buffer, "VmRSS");
        } while (getres != NULL && vmsize == NULL);
        if (vmsize != NULL)
            procmem = atoi(jump_to(vmsize, ' ', 1));
        free(buffer);
        free(pathname);
        fclose(stream);
    }
    return (float)procmem / (float)g->totmem * 100;
}

static void get_timecpu(process_t **proc, char *statline,
    glob_info_t *g)
{
    int utime = atoi(jump_to(statline, ' ', 13));
    int stime = atoi(jump_to(statline, ' ', 14));
    float starttime = atof(jump_to(statline, ' ', 21));
    long clock_ticks = sysconf(_SC_CLK_TCK);
    char *timep = calloc(256, 1);
    float secs = (double)(utime + stime) / clock_ticks;
    int hundredths = (secs - (int)secs) * 100;
    int am_secs = (int)secs % 60;
    int am_min = (secs / 60);

    sprintf(timep, "%2d:%02d.%02d", am_min, am_secs, hundredths);
    (*proc)->time = timep;
    (*proc)->cpu = (utime + stime) / (g->uptime - (starttime / clock_ticks));
}

void fill_a_process(process_t **process, char *statline,
    char *pathname, glob_info_t *glob)
{
    char *buffpr = calloc(20, 1);
    int pr = atoi(jump_to(statline, ' ', 17));
    long unsigned int vsize = atol(jump_to(statline, ' ', 22)) / 1024;
    int res = atoi(jump_to(statline, ' ', 23)) * 4;

    if (pr > -100)
        sprintf(buffpr, "%d", pr);
    else
        sprintf(buffpr, "rt");
    (*process)->pr = strdup(buffpr);
    (*process)->ni = atoi(jump_to(statline, ' ', 18));
    (*process)->virt = getvsize(vsize, 10000000);
    (*process)->res = getvsize(res, 1000000);
    (*process)->state = jump_to(statline, ' ', 2)[0];
    (*process)->shr = getshr(pathname);
    (*process)->comm = getcomm(statline);
    get_timecpu(process, statline, glob);
    free(buffpr);
}

process_t *get_process(char *pid, glob_info_t *glob)
{
    process_t *process = NULL;
    struct stat buff = {0};
    char *pathname = calloc(257, 1);
    int b = sprintf(pathname, "/proc/%s/stat", pid);
    int res = stat(pathname, &buff);
    char *statline = calloc(500, 1);
    FILE *stream = fopen(pathname, "r");

    if (b > 0 && res == 0 && stream != NULL) {
        process = calloc(1, sizeof(process_t));
        fgets(statline, 256, stream);
        process->user = getusrname(&buff);
        process->pid = pid;
        fill_a_process(&process, statline, pathname, glob);
        process->mem = getprocmem(pathname, glob);
        fclose(stream);
    }
    free(statline);
    free(pathname);
    return process;
}
