/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Prints
*/

#include "myradar.h"

int exit_error(char *str)
{
    my_put_str(2, str);
    return 84;
}

int display_help(void)
{
    struct stat buff = {0};
    int sres = stat("help.txt", &buff);
    int fd = open("help.txt", O_RDONLY);
    char *str = NULL;
    size_t n = 0;

    if (sres != 0 || fd == -1)
        return exit_error("Unable to find/open help.txt file.\n");
    n = buff.st_size;
    str = my_calloc(1, n + 1);
    if (str == NULL)
        return exit_error("Malloc failed.\n");
    read(fd, str, n);
    close(fd);
    write(1, str, n);
    free(str);
    return 0;
}

void print_nofilepath(int ac)
{
    my_put_str(2, "./my_radar: bad arguments: ");
    my_put_nbr(ac);
    my_put_str(2, " given but 1 is required\n");
    my_put_str(2, "retry with -h\n");
}
