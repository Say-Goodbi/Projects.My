/*
** EPITECH PROJECT, 2025
** My Radar
** File description:
** Planes go brbrbrrrrr
*/

#include "myradar.h"

void manage_event(sfEvent *event, game_t *game)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(game->win);
    if (event->type == sfEvtKeyPressed) {
        if (event->key.code == sfKeyL)
            interact_hitboxes(game);
        if (event->key.code == sfKeyS)
            interact_sprites_visibility(game);
        if (event->key.code == sfKeyC)
            interact_divide_visibility(game, event->key);
    }
}

void tick_action(game_t *game, sfClock *clock)
{
    sfTime elapsed = {0};

    move_planes(game);
    divide_chunk(game->original_chunk, game->subroot);
    print_framerate(game);
    elapsed = sfClock_getElapsedTime(clock);
    if (elapsed.microseconds >= 1000 / MAX_FRAMERATE) {
        draw_window(game);
        sfClock_restart(clock);
    }
    if (empty_chunk(game->original_chunk) == 1) {
        sfRenderWindow_close(game->win);
        my_put_str(1, "All planes either landed or crashed after ");
        my_put_str(1, sfText_getString(game->texts[1].text));
        my_put_str(1, ".\n");
    }
}

int my_radar(structures_t *towers_and_planes)
{
    game_t *game = new_game_instance(towers_and_planes);
    sfClock *clock = sfClock_create();
    sfEvent event;

    if (!game || !clock)
        return 84;
    while (sfRenderWindow_isOpen(game->win)) {
        while (sfRenderWindow_pollEvent(game->win, &event))
            manage_event(&event, game);
        tick_action(game, clock);
    }
    sfClock_destroy(clock);
    destroy_game_instance(game);
    return 0;
}

int main(int ac, char **av)
{
    FILE *stream = NULL;
    structures_t *towers_and_planes = my_calloc(1, sizeof(structures_t));
    int script_res = 0;

    if (ac != 2 || towers_and_planes == NULL) {
        print_nofilepath(ac - 1);
        return exit_error("");
    }
    if (my_strcmp("-h", av[1]) == 0)
        return display_help();
    stream = fopen(av[1], "r");
    if (stream == NULL)
        return exit_error("Error : Can't open the given filepath.\n");
    script_res = get_script(towers_and_planes, stream);
    fclose(stream);
    if (script_res != 0)
        return exit_error("Error : Given script is invalid.\n");
    script_res = my_radar(towers_and_planes);
    free(towers_and_planes);
    return script_res;
}
