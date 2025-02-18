/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Retrieves forth line of top.
*/

#include "include.h"

mem_t *getswap(void)
{
    mem_t *mem = calloc(1, sizeof(mem_t));
    FILE *file = fopen("/proc/meminfo", "r");
    char *buffer = calloc(2000, 1);

    if (file != NULL) {
        for (int i = 0; i < 3; i++)
            fgets(buffer, 200, file);
        mem->cache = atof(jump_to(buffer, ' ', 1));
        for (int i = 0; i < 12; i++)
            fgets(buffer, 200, file);
        mem->total = atof(jump_to(buffer, ' ', 1));
        fgets(buffer, 200, file);
        mem->free = atof(jump_to(buffer, ' ', 1));
        mem->used = mem->total - mem->free;
        fclose(file);
    }
    free(buffer);
    return mem;
}

char *my_getswap(void)
{
    mem_t *swp = getswap();
    char *str = swp != NULL ? calloc(100, 1) : NULL;
    double tot = swp->total / 1024.0;
    double fr = swp->free / 1024.0;
    double used = swp->used / 1024.0;
    double cache = swp->cache / 1024.0;

    free(swp);
    if (str != NULL) {
        sprintf(str, "\nMiB Swap:%9.1f total,%9.1f free,", tot, fr);
        sprintf(str + strlen(str), "%9.1f used.", used);
        sprintf(str + strlen(str), "%9.1f avail Mem", cache);
    }
    return str;
}
