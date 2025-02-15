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
    #include <unistd.h>
    #include <stdbool.h>

typedef struct llist_s {
    void *data;
    struct llist_s *next;
} llist_t;

typedef struct fflag_s {
    void (*fct);
    char *name;
} fflag_t;

/* Custom and subdivising functions to free */
typedef void (*mfree_t)(llist_t *, void *);

void mfree_dft(llist_t *subfree, void *target);
void mfree_array(llist_t *subfrees, void *target);
void mfree_list(llist_t *subfrees, void *target);

/* Freeing with formatted string */
void superfree(char *format, void *target);
void freef(char *format, ...);
/* Adding new flags to freef() */
void freef_add(char *name, void (*free_fct)());
/* Must use if you used freef() or free_add(), to end your program */
void freeflags_free(void);

/* Basic comparison functions */
typedef int (*cmp_fct_t)(void const *, void const *);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, size_t n);
int test_strcmp(void const *s1, void const *s2);

/* Recursive comparison functions based on multiple criterias */
int fieldscomp(void *elem1, void *elem2, cmp_fct_t *cmp_fct_list);
int multicomp(void *elem1, void *elem2, int nbcomp, ...);

/* Copy */
char *my_strcpy(char *dest, char *src);

/* Duplicating functions */
char *my_strndup(char *str, int n);
char *my_strdup(char *str);
char *concat(size_t flen, char **wa);
char *vstr_concat(int n, ...);

/* Memory functions */
void *my_memset(void *ptr, int value, size_t nbytes);
void *my_calloc(size_t amount, size_t size);

/* List manipulation */
void push_to_list(llist_t **begin, void *data);
void append_to_list(llist_t **begin, void *data);
llist_t *list_head(llist_t **begin);
llist_t *mergesort_list(llist_t *begin, cmp_fct_t *cmp_fcts);
bool delete_in_list(llist_t **begin, void const *ref, cmp_fct_t cmp_fct);
void destroy_list(llist_t *list, void (*destroy_node)(void *));
void my_map(llist_t *list, void (*apply_fct)(void **));
llist_t *find_node(llist_t *node, void const *ref,
    int (*cmp_fct)(void const *, void const *));

/* List sorting subfunctions, those can be used for other purposes too */
llist_t *find_list_half(llist_t *begin);
void submerge(llist_t **res, llist_t *l1, llist_t *l2);
llist_t *merge(llist_t *l1, llist_t *l2, cmp_fct_t *cmp_fcts);

/* List showcase */
void dft_putnode(void *s);
void newline_putnode(void *s);
void display_list(llist_t *begin, void(*disp_fct)(void *));

/* List testing */
int list_eq(llist_t *list, cmp_fct_t cmp, int nb, ...);

/* List transformations */
llist_t *str_to_word_list(char *av, char *seps);
void **list_to_array(llist_t *begin);
char **str_to_word_array(char *str, char *seps);
llist_t *word_array_to_list(char **wa);

/* Others */
bool is_alphanumeric(char *str);
bool is_alphanumeric_char(char c);
bool is_alpha_char(char c);
size_t my_strlen(char const *str);
int arr_len(void const **arr);
void my_putstr(char *str);
void my_put_nbr(int nb);
void vput_str(int n, ...);
llist_t **freeflags_get(void);

/* Do not use */
void free_a_fflag(void *flag);
#endif
