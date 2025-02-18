/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Creates
*/

#include "myradar.h"

sfVector2f plane_get_direction(plane_t *plane)
{
    float dist_x = plane->arrival.x - plane->departure.x;
    float dist_y = plane->arrival.y - plane->departure.y;
    float distance = sqrt(pow(dist_x, 2) + pow(dist_y, 2));
    sfVector2f direction = {dist_x / distance, dist_y / distance};

    return direction;
}

void fill_plane_boxes(plane_t *plane)
{
    sfVector2f size = {PLANE_HEIGHT, PLANE_WIDTH};
    sfVector2f origin = {PLANE_HEIGHT / 2, PLANE_WIDTH / 2};

    plane->hitbox = sfRectangleShape_create();
    plane->textbox = sfRectangleShape_create();
    sfRectangleShape_setSize(plane->hitbox, size);
    sfRectangleShape_setSize(plane->textbox, size);
    sfRectangleShape_setOrigin(plane->hitbox, origin);
    sfRectangleShape_setOrigin(plane->textbox, origin);
    sfRectangleShape_setRotation(plane->textbox, plane->rotation + 90.0);
    sfRectangleShape_setPosition(plane->hitbox, plane->pos);
    sfRectangleShape_setPosition(plane->textbox, plane->pos);
    sfRectangleShape_setFillColor(plane->hitbox, sfTransparent);
}

void fill_plane(plane_t *plane, char **structure)
{
    sfVector2f pos = {(float)my_atoi(structure[1]),
        (float)my_atoi(structure[2])};

    plane->pos = pos;
    plane->environment = UNCOVERED;
    plane->departure = plane->pos;
    plane->arrival.x = (float)my_atoi(structure[3]);
    plane->arrival.y = (float)my_atoi(structure[4]);
    plane->speed_pps = my_atof(structure[5]);
    plane->departure_delay = my_atof(structure[6]);
    plane->state = WAITING;
    plane->rotation = atan2((plane->arrival.y - plane->departure.y),
        (plane->arrival.x - plane->departure.x)) * 180 / M_PI - 90;
    plane->direction = plane_get_direction(plane);
    fill_plane_boxes(plane);
}

plane_t *create_plane(char **structure)
{
    plane_t *plane = NULL;

    if (n_are_posints(structure + 1, 4) != 0 ||
        n_are_posfloats(structure + 5, 2) != 0)
        return NULL;
    plane = my_calloc(1, sizeof(plane_t));
    if (plane == NULL)
        return NULL;
    fill_plane(plane, structure);
    return plane;
}
