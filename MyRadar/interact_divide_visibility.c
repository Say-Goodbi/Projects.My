/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** My radar
*/

#include "myradar.h"

void interact_divide_visibility(game_t *game, sfKeyEvent event)
{
    if (event.alt && game->subroot < SUBROOT_LIMIT)
        game->subroot += 1;
    if (event.control && game->subroot > 2)
        game->subroot -= 1;
    if (event.control || event.alt)
        return;
    if (game->show_divides == false) {
        game->show_divides = true;
    } else {
        game->show_divides = false;
    }
}
