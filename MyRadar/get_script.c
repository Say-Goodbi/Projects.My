/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** Takes all towers and planes from the given filestream.
*/

#include "myradar.h"

void replace_cr_by_nil(char *str)
{
    int i = 0;

    if (str == NULL)
        return;
    while (str[i] != 0) {
        if (str[i] == '\n')
            str[i] = 0;
        i++;
    }
}

// 0 means no error encountered.
int get_script(structures_t *towers_and_planes, FILE *stream)
{
    char *lineptr = NULL;
    int getres = 0;
    int appendres = 0;
    size_t buffsize = 0;

    if (stream == NULL)
        return -1;
    getres = getline(&lineptr, &buffsize, stream);
    replace_cr_by_nil(lineptr);
    while (getres > 0 && appendres == 0) {
        appendres = append_structure(towers_and_planes, lineptr);
        getres = getline(&lineptr, &buffsize, stream);
        replace_cr_by_nil(lineptr);
    }
    if (lineptr)
        free(lineptr);
    return appendres;
}
