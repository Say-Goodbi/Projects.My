/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** New game instance
*/

#include "myradar.h"

game_t *check_game_instance(game_t *game)
{
    if (!game || !game->textures || !game->texts || !game->win)
        return NULL;
    if (game->planes == NULL) {
        my_put_str(2, "No planes found.\n");
        return NULL;
    }
    show_hitboxes(game);
    return game;
}

void set_background(game_t *game, sfVideoMode mode)
{
    sfVector2f size = {mode.width, mode.height};
    sfRectangleShape *rect = sfRectangleShape_create();

    if (rect == NULL)
        return;
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setTexture(rect, game->textures[2].texture, sfFalse);
    game->background = rect;
}

game_t *new_game_instance(structures_t *towers_and_planes)
{
    game_t *game = my_calloc(1, sizeof(game_t));
    sfVideoMode mode = {SCREEN_WIDTH, SCREEN_HEIGHT, 32};

    if (game == NULL)
        return NULL;
    game->subroot = SUBCHUNK_ROOT;
    game->textures = load_textures();
    game->texts = load_texts(game);
    game->win = sfRenderWindow_create(mode, "My Radar",
        sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win, MAX_FRAMERATE);
    game->entities_shown = true;
    game->hitboxes_shown = true;
    game->towers = (tower_t **)list_to_array(towers_and_planes->towers);
    game->planes = (plane_t **)list_to_array(towers_and_planes->planes);
    set_texture_planes(game->textures, game->planes);
    set_texture_towers(game->textures, game->towers);
    game->original_chunk = create_original_chunk(game->planes, game->towers);
    set_background(game, mode);
    return check_game_instance(game);
}

void free_planes_and_towers(game_t *game)
{
    for (int i = 0; game->planes[i]; i++) {
        sfRectangleShape_destroy(game->planes[i]->hitbox);
        sfRectangleShape_destroy(game->planes[i]->textbox);
        free(game->planes[i]);
    }
    free(game->planes);
    for (int i = 0; game->towers[i]; i++) {
        sfRectangleShape_destroy(game->towers[i]->rectangle);
        sfCircleShape_destroy(game->towers[i]->circle);
        free(game->towers[i]);
    }
    free(game->towers);
}

void destroy_game_instance(game_t *game)
{
    stop_fps();
    sfRectangleShape_destroy(game->original_chunk->rect);
    sfRectangleShape_destroy(game->background);
    free(game->original_chunk);
    sfFont_destroy(game->font);
    sfRenderWindow_destroy(game->win);
    free_planes_and_towers(game);
    for (int i = 0; i < TEXTURES_NB; i++) {
        sfTexture_destroy(game->textures[i].texture);
    }
    free(game->textures);
    for (int i = 0; i < TEXTS_NB; i++) {
        sfText_destroy(game->texts[i].text);
    }
    free(game->texts);
    free(game);
}
