/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** Takes argv & argc and returns a struct containing params.
*/

#include "include.h"

int change_values(int ac, char **av, args_t *opts, int *i)
{
    int r = 1;

    while (*i < ac - 1) {
        if (strcmp(av[*i], "-d") == 0 && *i < ac - 1 && av[*i + 1][0] != '-') {
            opts->d = atof(av[*i + 1]);
            r += 2;
            (*i)++;
        }
        if (strcmp(av[*i], "-n") == 0 && *i < ac - 1 && av[*i + 1][0] != '-') {
            opts->n = atoi(av[*i + 1]);
            r += 2;
            (*i)++;
        }
        if (strcmp(av[*i], "-U") == 0 && *i < ac - 1 && av[*i + 1][0] != '-') {
            opts->U = strdup(av[(*i) + 1]);
            r += 2;
            (*i)++;
        }
        (*i)++;
    }
    return r == ac ? 1 : 0;
}

args_t *args_parse(int ac, char **av)
{
    args_t *opts = calloc(1, sizeof(args_t));
    int i = 0;

    if (opts == NULL)
        return NULL;
  (void)ac, (void)av;
    opts->d = 3.0;
    opts->n = -2;
    opts->U = NULL;
    if (change_values(ac, av, opts, &i) == 1) {
        opts->n += 1;
        return opts;
    }
    endwin();
    return NULL;
}
