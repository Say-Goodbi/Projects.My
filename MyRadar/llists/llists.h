/*
** EPITECH PROJECT, 2024
** Libs
** File description:
** Llists
*/


#ifndef LLISTS_H_
    #define LLISTS_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdarg.h>
typedef struct llist_s {
    void *data;
    struct llist_s *next;
} llist_t;

typedef int (*cmp_fct_t)(void *, void *);
int fieldscomp(void *elem1, void *elem2, cmp_fct_t *cmp_fct_list);
int multicomp(void *elem1, void *elem2, int nbcomp, ...);
void *my_memset(void *ptr, int value, size_t nbytes);
void *my_calloc(size_t amount, size_t size);
void append_to_list(llist_t **begin, void *data);
void delete_in_list(llist_t **begin, void const *ref, cmp_fct_t cmp_fct);
void destroy_list(llist_t *list);
void display_list(llist_t *begin, void(*disp_fct)(void *));
void push_to_list(llist_t **begin, void *data);
llist_t *mergesort_list(llist_t *begin, cmp_fct_t *cmp_fcts);
int list_size(llist_t *begin);
void **list_to_array(llist_t *begin);
#endif
