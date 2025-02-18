/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Set textures
*/

#include "myradar.h"

void set_texture_planes(my_texture_t *textures, plane_t **planes)
{
    int i = 0;
    sfTexture *texture = look_for_texture(textures, "Plane");

    if (planes == NULL || texture == NULL)
        return;
    while (planes[i] != NULL) {
        sfRectangleShape_setTexture(planes[i]->textbox,
            texture, sfTrue);
        i++;
    }
}

void set_texture_towers(my_texture_t *textures, tower_t **towers)
{
    int i = 0;
    sfTexture *texture = look_for_texture(textures, "Tower");

    if (towers == NULL || texture == NULL)
        return;
    while (towers[i] != NULL) {
        sfRectangleShape_setTexture(towers[i]->rectangle,
            texture, sfTrue);
        i++;
    }
}
