/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Collides 2
*/

#include "myradar.h"

bool collide_squares(sfRectangleShape *chunk_square, sfRectangleShape *hitbox)
{
    sfVector2f chunk_pos = sfRectangleShape_getPosition(chunk_square);
    sfVector2f size = sfRectangleShape_getSize(chunk_square);
    sfVector2f box_pos = sfRectangleShape_getPosition(hitbox);

    box_pos.x -= PLANE_WIDTH / 2;
    box_pos.y -= PLANE_WIDTH / 2;
    if (box_pos.x >= chunk_pos.x - PLANE_WIDTH &&
        box_pos.x <= chunk_pos.x + size.x + PLANE_WIDTH &&
        box_pos.y >= chunk_pos.y - PLANE_WIDTH &&
        box_pos.y <= chunk_pos.y + size.y + PLANE_WIDTH) {
        return true;
    }
    return false;
}

void append_if_pcollide(chunk_t *chunk, plane_t *plane, llist_t **planes_list)
{
    if (plane->state != FLYING ||
        (COVER_BEFORE && plane->environment == SAFE))
        return;
    if (collide_squares(chunk->rect, plane->hitbox)) {
        chunk->amount_crafts += 1;
        append_to_list(planes_list, plane);
    }
}

bool collide_chunk_tower(sfVector2f chunk_pos,
    sfVector2f chunk_size, tower_t *tower)
{
    sfVector2f tower_pos = sfRectangleShape_getPosition(tower->rectangle);
    float closest_x = tower_pos.x;
    float closest_y = tower_pos.y;
    float dist = 0;

    closest_to_chunk(&closest_x, chunk_pos.x, chunk_size.x);
    closest_to_chunk(&closest_y, chunk_pos.y, chunk_size.y);
    dist = distance(closest_x - tower_pos.x, closest_y - tower_pos.y);
    if (dist <= tower->radius) {
        return true;
    } else {
        return false;
    }
}

void append_if_tcollide(chunk_t *chunk, tower_t *tower, llist_t **towers_list)
{
    sfVector2f size = sfRectangleShape_getSize(chunk->rect);
    sfVector2f pos = sfRectangleShape_getPosition(chunk->rect);

    if (collide_chunk_tower(pos, size, tower) == true) {
        chunk->amount_towers += 1;
        append_to_list(towers_list, tower);
    }
}
