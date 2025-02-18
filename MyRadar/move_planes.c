/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Move planes
*/

#include "myradar.h"

bool is_beyond_destination(plane_t *p)
{
    if (distance((int)p->pos.x - (int)p->arrival.x,
        (int)p->pos.y - (int)p->arrival.y) < PLANE_WIDTH / 2)
        return true;
    return false;
}

void move_a_plane(plane_t *p)
{
    sfVector2f pos = p->pos;
    sfVector2f speed = {0, 0};

    speed.x = p->direction.x * p->speed_pps;
    speed.y = p->direction.y * p->speed_pps;
    pos.x += 1.0 / MAX_FRAMERATE * speed.x;
    pos.y += 1.0 / MAX_FRAMERATE * speed.y;
    sfRectangleShape_setPosition(p->hitbox, pos);
    sfRectangleShape_setPosition(p->textbox, pos);
    p->pos = pos;
}

void move_planes(game_t *game)
{
    plane_t **planes = game->planes;
    plane_t *p = NULL;

    for (int i = 0; planes[i] != NULL; i++) {
        p = planes[i];
        if (p->state == WAITING && p->departure_delay <= game->seconds)
            p->state = FLYING;
        if (p->state == FLYING && is_beyond_destination(p))
            p->state = DEAD;
        if (p->state == FLYING) {
            move_a_plane(p);
        }
    }
}
