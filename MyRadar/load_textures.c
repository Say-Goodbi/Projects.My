/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** Loadsz textures from png file
*/

#include "myradar.h"

sfTexture *texture_from_file(const char *str)
{
    return sfTexture_createFromFile(str, NULL);
}

my_texture_t *load_textures(void)
{
    my_texture_t *textures = my_calloc(TEXTURES_NB, sizeof(my_texture_t));
    my_texture_t tplane = {"Plane", texture_from_file("png/plane.png")};
    my_texture_t ttower = {"Tower", texture_from_file("png/tower.png")};
    my_texture_t tbackground = {"Background",
        texture_from_file("png/map.png")};

    if (textures == NULL)
        return NULL;
    textures[0] = tplane;
    textures[1] = ttower;
    textures[2] = tbackground;
    for (int i = 0; i < TEXTURES_NB; i++) {
        if (textures[i].texture == NULL) {
            my_put_str(2, textures[i].name);
            my_put_str(2, " not loaded.\n");
            return NULL;
        }
    }
    return textures;
}
