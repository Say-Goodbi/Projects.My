/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Gets uptime, in an array for hours, minutes
*/

#include "include.h"

char *treat_uptime(char *raw_uptime)
{
    time_t global = time(NULL);
    struct tm *t = localtime(&global);
    char *uptime = calloc(120, 1);
    int secs = atoi(raw_uptime);
    int am_min = (secs / 60) % 60;
    int am_hour = secs / 3600 % 24;
    int am_day = secs / 3600 / 24;

    free(raw_uptime);
    sprintf(uptime, "%02d:%02d:%02d up ",
            t->tm_hour, t->tm_min, t->tm_sec);
    if (am_day > 1)
        sprintf(uptime + strlen(uptime), "%d days,", am_day);
    else if (am_day == 1)
        sprintf(uptime + strlen(uptime), "%d day,", am_day);
    if (am_hour > 0)
        sprintf(uptime + strlen(uptime), "%3d:%02d,", am_hour, am_min);
    else
        sprintf(uptime + strlen(uptime), "%d min,", am_min);
    return uptime;
}

char *my_getuptime(void)
{
    FILE *stream = fopen("/proc/uptime", "r");
    char *buffer = calloc(50, 1);
    char *uptime = NULL;

    if (stream == NULL) {
        free(buffer);
        return NULL;
    }
    fgets(buffer, 50, stream);
    fclose(stream);
    uptime = treat_uptime(buffer);
    return uptime;
}
