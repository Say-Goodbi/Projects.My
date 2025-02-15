/*
** EPITECH PROJECT, 2025
** Lib llist
** File description:
** unit test
*/

#include "tests.h"

Test(word_array_to_list, simple_wordlist)
{
    char *str = "Aloah\n mister\n googa\n";
    char **array = str_to_word_array(str, " ");
    llist_t *wordlist = word_array_to_list(array);

    for (int i = arr_len((void const **)array) - 1; wordlist; i--) {
        cr_assert_str_eq(array[i], (char *)wordlist->data);
        wordlist = wordlist->next;
    }
    cr_assert(wordlist == NULL);
}

Test(word_array_to_list, no_wordlist)
{
    char *str = "  ";
    char *str2 = NULL;
    char **array = str_to_word_array(str2, " ");
    llist_t *wordlist = word_array_to_list(array);

    cr_assert(array == NULL);
    cr_assert(wordlist == NULL);
}
