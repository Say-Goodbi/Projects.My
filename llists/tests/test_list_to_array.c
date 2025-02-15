/*
** EPITECH PROJECT, 2025
** Lib llists
** File description:
** Test
*/

#include "tests.h"

Test(list_to_array, simple_nodes, .init = redirect_all_std)
{
    llist_t *list = NULL;
    char **array = NULL;

    append_to_list(&list, "data");
    cr_assert_str_eq((char *)list->data, "data");
    append_to_list(&list, "value n*2");
    cr_assert_str_eq((char *)list->next->data, "value n*2");
    array = (char **)list_to_array(list);
    cr_assert_str_eq(array[0], "data");
    cr_assert_str_eq(array[1], "value n*2");
    cr_assert(array[2] == NULL);
    free(array);
}

Test(list_to_array, no_nodes, .init = redirect_all_std)
{
    llist_t *list = NULL;
    char **array = (char **)list_to_array(list);

    cr_assert(array == NULL);
}
