/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Retrieves forth line of top.
*/

#include "include.h"

void cacheused(char *buffer, FILE *file, mem_t *mem)
{
    double buffermem = 0.0;

    fgets(buffer, 200, file);
    fgets(buffer, 200, file);
    buffermem = atof(jump_to(buffer, ' ', 1));
    fgets(buffer, 200, file);
    mem->cache = atof(jump_to(buffer, ' ', 1)) + buffermem;
    for (int i = 0; i < 21; i++) {
        fgets(buffer, 200, file);
    }
    mem->cache += atof(jump_to(buffer, ' ', 1));
    mem->used = mem->total - mem->free - mem->cache;
}

mem_t *getmem(void)
{
    mem_t *mem = calloc(1, sizeof(mem_t));
    FILE *file = fopen("/proc/meminfo", "r");
    char *buffer = calloc(2000, 1);

    if (file != NULL) {
        fgets(buffer, 200, file);
        mem->total = atof(jump_to(buffer, ' ', 1));
        fgets(buffer, 200, file);
        mem->free = atof(jump_to(buffer, ' ', 1));
        cacheused(buffer, file, mem);
        fclose(file);
    }
    free(buffer);
    return mem;
}

char *my_getmem(void)
{
    mem_t *mem = getmem();
    char *str = mem != NULL ? calloc(100, 1) : NULL;
    double tot = mem->total / 1024.0;
    double fr = mem->free / 1024.0;
    double used = mem->used / 1024.0;
    double cache = mem->cache / 1024.0;

    free(mem);
    if (str != NULL) {
        sprintf(str, "\nMiB Mem :%9.1f total,%9.1f free,", tot, fr);
        sprintf(str + strlen(str), "%9.1f used,", used);
        sprintf(str + strlen(str), "%9.1f buff/cache", cache);
    }
    return str;
}
