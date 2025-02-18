/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Draws everything
*/

#include "myradar.h"

void draw_chunk(game_t *game, chunk_t *chunk)
{
    if (!chunk || game->show_divides == false)
        return;
    if (DRAW_EMPTY_CHUNKS)
        sfRenderWindow_drawRectangleShape(game->win, chunk->rect, NULL);
    if (chunk->subchunks) {
        if (!DRAW_EMPTY_CHUNKS)
            sfRenderWindow_drawRectangleShape(game->win, chunk->rect, NULL);
        for (int i = 0; chunk->subchunks[i]; i++) {
            draw_chunk(game, chunk->subchunks[i]);
        }
    }
}

void draw_a_tower(game_t *game, tower_t *tower)
{
    if (game->entities_shown)
        sfRenderWindow_drawRectangleShape(game->win, tower->rectangle, NULL);
    sfRenderWindow_drawCircleShape(game->win, tower->circle, NULL);
}

void draw_a_plane(game_t *game, plane_t *plane)
{
    if (plane->state == FLYING) {
        sfRenderWindow_drawRectangleShape(game->win, plane->hitbox, NULL);
        if (game->entities_shown)
            sfRenderWindow_drawRectangleShape(game->win, plane->textbox, NULL);
    }
}

void actualize_timer(game_t *game)
{
    int seconds = (int)game->seconds % 60;
    size_t minutes = game->seconds / 60;
    my_text_t timer_text = game->texts[1];
    char str[7] = "--:--";

    if (minutes < 100) {
        str[0] = minutes / 10 + 48;
        str[1] = minutes % 10 + 48;
        str[3] = seconds / 10 + 48;
        str[4] = seconds % 10 + 48;
    }
    sfText_setString(timer_text.text, str);
}

void draw_window(game_t *game)
{
    plane_t **planes = game->planes;
    tower_t **towers = game->towers;

    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_drawRectangleShape(game->win, game->background, NULL);
    draw_chunk(game, game->original_chunk);
    if (towers) {
        for (int i = 0; towers[i] != NULL; i++) {
            draw_a_tower(game, towers[i]);
        }
    }
    for (int i = 0; planes[i] != NULL; i++) {
        draw_a_plane(game, planes[i]);
    }
    actualize_timer(game);
    for (int i = 0; i < TEXTS_NB; i++)
        sfRenderWindow_drawText(game->win, game->texts[i].text, NULL);
    sfRenderWindow_display(game->win);
}
