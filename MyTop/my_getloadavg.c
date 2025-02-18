/*
** EPITECH PROJECT, 2024
** Bs My_top
** File description:
** Gets load average
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int my_strlen_to_char(char const *str, char end)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != end)
        i++;
    return i;
}

int fill_loadavg(double loadavg[], int nelem)
{
    int fd = open("/proc/loadavg", O_RDONLY);
    int i = 0;
    int word = 0;
    char buff[128];

    if (fd > 0) {
        read(fd, buff, 128);
        while (nelem < 4 && word < nelem) {
            loadavg[word] = atof(buff + i);
            word++;
            i += my_strlen_to_char(buff, ' ') + 1;
        }
        close(fd);
    }
    return fd > 0 && nelem > 0 && nelem < 4 ? 0 : -1;
}

char *my_getloadavg(void)
{
    char *str = calloc(34, 1);
    double *lavg = calloc(3, sizeof(double));

    fill_loadavg(lavg, 3);
    sprintf(str, "load average: %.2f, %.2f, %.2f", lavg[0], lavg[1], lavg[2]);
    free(lavg);
    return str;
}
