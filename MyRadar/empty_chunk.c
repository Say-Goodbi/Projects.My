/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** empties a chunk
*/

#include "myradar.h"

void empty_a_chunk(chunk_t *chunk)
{
    if (chunk == NULL)
        return;
    if (chunk->subchunks) {
        for (int i = 0; chunk->subchunks[i]; i++)
            empty_a_chunk(chunk->subchunks[i]);
        free(chunk->subchunks);
    } else {
        structure_collisions(chunk->towers, chunk->planes);
    }
    if (chunk->depth == 0)
        return;
    sfRectangleShape_destroy(chunk->rect);
    free(chunk->planes);
    free(chunk->towers);
    free(chunk);
}

int empty_chunk(chunk_t *chunk)
{
    int alive_planes = 0;

    if (!chunk->planes)
        return 0;
    for (int i = 0; chunk->planes[i]; i++) {
        chunk->planes[i]->environment = UNCOVERED;
        sfRectangleShape_setOutlineColor(chunk->planes[i]->hitbox, sfYellow);
        if (chunk->planes[i]->state != DEAD)
            alive_planes++;
    }
    empty_a_chunk(chunk);
    if (alive_planes == 0)
        return 1;
    return 0;
}
