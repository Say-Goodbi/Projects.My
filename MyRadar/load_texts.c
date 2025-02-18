/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** Loads texts
*/

#include "myradar.h"

void set_text(my_text_t text, sfFont *font)
{
    sfText_setFont(text.text, font);
    sfText_setCharacterSize(text.text, text.csize);
    sfText_setFillColor(text.text, sfWhite);
    sfText_setOutlineColor(text.text, sfBlack);
    sfText_setOutlineThickness(text.text, 4.0);
    sfText_setPosition(text.text, text.pos);
    sfText_setString(text.text, text.name);
}

my_text_t *load_texts(game_t *game)
{
    my_text_t *texts = my_calloc(TEXTS_NB, sizeof(my_text_t));
    sfFont *font = sfFont_createFromFile("Blockletter.otf");
    my_text_t fps_text = {"    FPS", sfText_create(), {15, 80}, 30};
    my_text_t timer_text = {"Timer", sfText_create(), {10, 20}, 50};

    if (texts == NULL)
        return NULL;
    if (font == NULL) {
        my_put_str(2, "Blockletter.otf not loaded.");
        return NULL;
    }
    game->font = font;
    texts[0] = fps_text;
    texts[1] = timer_text;
    for (int i = 0; i < TEXTS_NB; i++) {
        set_text(texts[i], font);
    }
    return texts;
}
