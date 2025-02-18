/*
** EPITECH PROJECT, 2025
** My radar
** File description:
** looks for a sfTexture from given name.
*/

#include "myradar.h"

sfTexture *look_for_texture(my_texture_t *textures, char *name)
{
    int ti = 0;
    sfTexture *texture = NULL;

    while (ti < TEXTURES_NB && my_strcmp(textures[ti].name, name) != 0) {
        ti++;
    }
    if (ti == TEXTURES_NB)
        return NULL;
    texture = textures[ti].texture;
    return texture;
}
