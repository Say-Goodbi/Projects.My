/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** My radar
*/

#include "myradar.h"

void interact_sprites_visibility(game_t *game)
{
    if (game->entities_shown == false) {
        game->entities_shown = true;
    } else {
        game->entities_shown = false;
    }
}
