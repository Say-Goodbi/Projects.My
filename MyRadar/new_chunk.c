/*
** EPITECH PROJECT, 2025
** my_tadar
** File description:
** File desc
*/

#include "myradar.h"

bool chunk_could_divide(chunk_t *chunk)
{
    return (chunk->size.x > MAX_DEPTH_WIDTH &&
        chunk->amount_crafts >= PLANES_MAX);
}

void claim_structures(chunk_t *chunk, chunk_t *parent)
{
    llist_t *planes_list = NULL;
    llist_t *towers_list = NULL;
    int n_planes = parent->amount_crafts;
    int n_towers = parent->amount_towers;

    for (int i = 0; i < n_planes; i++) {
        append_if_pcollide(chunk, parent->planes[i], &planes_list);
    }
    chunk->planes = (plane_t **)list_to_array(planes_list);
    for (int i = 0; i < n_towers; i++) {
        append_if_tcollide(chunk, parent->towers[i], &towers_list);
    }
    chunk->towers = (tower_t **)list_to_array(towers_list);
}

chunk_t *create_original_chunk(plane_t **planes, tower_t **towers)
{
    chunk_t *chunk = my_calloc(1, sizeof(chunk_t));
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f firstpos = {0, 0};
    sfVector2f size = {SCREEN_WIDTH, SCREEN_HEIGHT};

    if (chunk == NULL || rect == NULL)
        return NULL;
    sfRectangleShape_setPosition(rect, firstpos);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setSize(rect, size);
    chunk->pos = firstpos;
    chunk->size = size;
    chunk->depth = 0;
    chunk->rect = rect;
    chunk->planes = planes;
    chunk->amount_crafts = ptrlen((char **)chunk->planes);
    chunk->towers = towers;
    chunk->amount_towers = ptrlen((char **)chunk->towers);
    return chunk;
}

// Claim craftss from parent chunk and collides.
chunk_t *create_subchunk(chunk_t *parent, sfVector2f pos, sfVector2f size,
    char subroot)
{
    chunk_t *chunk = my_calloc(1, sizeof(chunk_t));
    sfRectangleShape *rect = sfRectangleShape_create();

    if (chunk == NULL || rect == NULL)
        return NULL;
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setFillColor(rect, sfTransparent);
    chunk->rect = rect;
    chunk->size = size;
    chunk->pos = pos;
    if (parent->depth > FAST_TOWER_DEPTH)
        change_envs(parent->towers, parent->planes);
    claim_structures(chunk, parent);
    chunk->depth = parent->depth + 1;
    if (chunk_could_divide(chunk)) {
        divide_chunk(chunk, subroot);
    }
    return chunk;
}

void divide_chunk(chunk_t *parent, char subroot)
{
    sfVector2f parentpos = parent->pos;
    sfVector2f psize = parent->size;
    sfVector2f childsize = {psize.x / subroot, psize.y / subroot};
    sfVector2f pos = parentpos;

    if (parent->size.x < MAX_DEPTH_WIDTH)
        return;
    parent->subchunks = my_calloc(subroot * subroot + 1,
        sizeof(chunk_t *));
    if (!parent->subchunks)
        return;
    for (int i = 0; i < subroot; i++) {
        for (int j = 0; j < subroot; j++) {
            parent->subchunks[i * subroot + j] = create_subchunk(parent,
                pos, childsize, subroot);
            pos.x += childsize.x;
        }
        pos.x = parentpos.x;
        pos.y += childsize.y;
    }
}
