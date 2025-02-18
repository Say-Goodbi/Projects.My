/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Creates
*/

#include "myradar.h"

void fill_tower_circle(tower_t *tower, sfVector2f pos)
{
    sfVector2f circle_origin = {tower->radius, tower->radius};

    tower->circle = sfCircleShape_create();
    sfCircleShape_setOutlineColor(tower->circle, sfBlue);
    sfCircleShape_setOrigin(tower->circle, circle_origin);
    sfCircleShape_setPosition(tower->circle, pos);
    sfCircleShape_setRadius(tower->circle, tower->radius);
    sfCircleShape_setFillColor(tower->circle, sfTransparent);
}

void fill_tower(tower_t *tower, char **structure)
{
    float radius = (float)my_atoi(structure[3]) * 1.5;
    sfVector2f size = {TOWER_HEIGHT * radius, TOWER_WIDTH * radius};
    sfVector2f origin = {(TOWER_HEIGHT * radius) / 2,
        (TOWER_WIDTH * radius) / 2};
    sfVector2f pos = {(float)my_atoi(structure[1]),
        (float)my_atoi(structure[2])};

    tower->pos = pos;
    tower->radius = radius;
    tower->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(tower->rectangle, size);
    sfRectangleShape_setOrigin(tower->rectangle, origin);
    sfRectangleShape_setPosition(tower->rectangle, pos);
    fill_tower_circle(tower, pos);
}

tower_t *create_tower(char **structure)
{
    tower_t *tower = NULL;

    if (n_are_posints(structure + 1, 3) != 0)
        return NULL;
    tower = my_calloc(1, sizeof(tower_t));
    if (tower == NULL)
        return NULL;
    fill_tower(tower, structure);
    return tower;
}
