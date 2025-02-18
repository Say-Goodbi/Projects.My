/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Gets uptime, in an array for hours, minutes
*/

#include "include.h"

char *treat_users(FILE *file)
{
    struct utmp *ut = calloc(1, sizeof(struct utmp));
    char *string = calloc(20, 1);
    int nb = 0;
    int res = 1;

    while (res > 0) {
        res = fread(ut, sizeof(struct utmp), 1, file);
        if (res > 0 && ut->ut_type == USER_PROCESS)
            nb++;
    }
    free(ut);
    if (nb > 1)
        sprintf(string, "%d users,", nb);
    else
        sprintf(string, "%d user,", nb);
    return string;
}

char *my_getusers(void)
{
    FILE *stream = fopen("/var/run/utmp", "r");
    char *string = NULL;

    if (stream == NULL) {
        free(string);
        return NULL;
    }
    string = treat_users(stream);
    fclose(stream);
    return string;
}
