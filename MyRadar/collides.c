/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Collides
*/

#include "myradar.h"

bool is_in_circle(sfVector2f pos, tower_t *t)
{
    if (distance(pos.x - t->pos.x, pos.y - t->pos.y) < t->radius)
        return true;
    return false;
}

bool collide_square_tower(sfVector2f plane_pos,
    sfVector2f plane_size, tower_t *tower)
{
    sfVector2f tower_pos = tower->pos;
    float closest_x = tower_pos.x;
    float closest_y = tower_pos.y;
    float dist = 0;

    closest_to_rect(&closest_x, plane_pos.x, plane_size.x);
    closest_to_rect(&closest_y, plane_pos.y, plane_size.y);
    dist = distance(closest_x - tower_pos.x, closest_y - tower_pos.y);
    if (dist <= tower->radius) {
        return true;
    } else {
        return false;
    }
}

void collide_plane_tower(plane_t *plane, sfVector2f plane_pos,
    sfVector2f plane_size, tower_t *tower)
{
    bool within_guard = false;

    plane_size.x /= 2;
    plane_size.y /= 2;
    if (DO_PRECISION)
        within_guard = collide_square_tower(plane_pos, plane_size, tower);
    else
        within_guard = is_in_circle(plane_pos, tower);
    if (within_guard == true) {
        plane->environment = SAFE;
        sfRectangleShape_setOutlineColor(plane->hitbox, sfGreen);
    }
}

bool collide_plane_plane(plane_t *plane_1, plane_t *plane_2)
{
    sfVector2f p1 = plane_1->pos;
    sfVector2f p2 = plane_2->pos;
    sfVector2f s1 = sfRectangleShape_getSize(plane_1->hitbox);
    sfVector2f s2 = sfRectangleShape_getSize(plane_2->hitbox);

    if (plane_1->environment == SAFE || plane_2->environment == SAFE)
        return false;
    if (p1.x < p2.x + s2.x && p1.x + s1.x > p2.x &&
        p1.y < p2.y + s2.y && s1.y + p1.y > p2.y)
        return true;
    else
        return false;
}

void collide_with_planes(plane_t **planes, int i)
{
    plane_t *p1 = planes[i];

    for (int k = 0; planes[k]; k++) {
        if (k == i || planes[i]->state == DEAD || planes[k]->state == DEAD ||
            planes[i]->environment == SAFE || planes[k]->environment == SAFE)
            continue;
        if (collide_plane_plane(p1, planes[k])) {
            p1->state = DEAD;
            planes[k]->state = DEAD;
        }
    }
}
