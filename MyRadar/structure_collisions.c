/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** Something somehow
*/

#include "myradar.h"

void change_envs(tower_t **towers, plane_t **planes)
{
    sfVector2f plane_pos = {0};
    sfVector2f plane_size = {PLANE_WIDTH, PLANE_HEIGHT};

    for (int i = 0; planes[i]; i++) {
        if (planes[i]->state != FLYING || planes[i]->environment == SAFE)
            continue;
        plane_pos = planes[i]->pos;
        for (int j = 0; towers && towers[j]; j++) {
            collide_plane_tower(planes[i], plane_pos, plane_size, towers[j]);
        }
    }
}

void structure_collisions(tower_t **towers, plane_t **planes)
{
    if (planes == NULL) {
        return;
    }
    change_envs(towers, planes);
    for (int i = 0; planes[i]; i++) {
        if (planes[i]->environment == SAFE)
            continue;
        if (DO_PLANES_COLLIDE)
            collide_with_planes(planes, i);
    }
}
