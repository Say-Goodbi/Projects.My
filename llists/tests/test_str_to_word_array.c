/*
** EPITECH PROJECT, 2025
** Lib llist
** File description:
** unit test
*/

#include "tests.h"

Test(str_to_word_array, sinmple_words, .init = redirect_all_std)
{
    char *str = "Aloah mister googa";
    char **array = str_to_word_array(str, " ");

    cr_assert_str_eq(array[0], "Aloah");
    cr_assert_str_eq(array[1], "mister");
    cr_assert_str_eq(array[2], "googa");
    cr_assert(array[3] == NULL);
    free(array[0]);
    free(array[1]);
    free(array[2]);
    free(array);
}

Test(str_to_word_array, many_spaces, .init = redirect_all_std)
{
    char *str = " Aloah   mister   googa  ";
    char **array = str_to_word_array(str, " ");

    cr_assert_str_eq(array[0], "Aloah");
    cr_assert_str_eq(array[1], "mister");
    cr_assert_str_eq(array[2], "googa");
    cr_assert(array[3] == NULL);
    free(array[0]);
    free(array[1]);
    free(array[2]);
    free(array);
}

Test(str_to_word_array, no_words, .init = redirect_all_std)
{
    char *str = "  ";
    char *str2 = NULL;
    char **array = str_to_word_array(str2, " ");

    cr_assert(array == NULL);
    array = str_to_word_array(str, " ");
    cr_assert(array == NULL);
    cr_assert(arr_len((void const **)array) == 0);
}
