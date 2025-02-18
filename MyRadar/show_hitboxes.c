/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Enables the sight of hitboxes
*/

#include "myradar.h"

void show_hitboxes(game_t *game)
{
    if (!game->planes)
        return;
    for (int i = 0; game->planes[i] != NULL; i++) {
        sfRectangleShape_setOutlineThickness(game->planes[i]->hitbox,
            1.0);
        sfRectangleShape_setOutlineColor(game->planes[i]->hitbox,
            sfYellow);
    }
    if (game->towers) {
        for (int i = 0; game->towers[i] != NULL; i++) {
            sfCircleShape_setOutlineThickness(game->towers[i]->circle,
                3.0);
        }
    }
}

void hide_hitboxes(game_t *game)
{
    if (!game->planes)
        return;
    for (int i = 0; game->planes[i] != NULL; i++) {
        sfRectangleShape_setOutlineThickness(game->planes[i]->hitbox,
            0.0);
    }
    if (game->towers) {
        for (int i = 0; game->towers[i] != NULL; i++) {
            sfCircleShape_setOutlineThickness(game->towers[i]->circle,
                0.0);
        }
    }
}

void interact_hitboxes(game_t *game)
{
    if (game->hitboxes_shown) {
        hide_hitboxes(game);
        game->hitboxes_shown = false;
    } else {
        show_hitboxes(game);
        game->hitboxes_shown = true;
    }
}
