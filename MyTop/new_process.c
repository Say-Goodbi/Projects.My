/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** All information about new process
*/

process_t *new_process(DIR *dir)
{
    process_t *process = calloc(sizeof(process_t));

    process->pr = malloc(20);
    process_get_stat(process);
}
