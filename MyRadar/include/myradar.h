/*
** EPITECH PROJECT, 2024
** MyRadar
** File description:
** 299042 302420
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
    #include "../llists/llists.h"
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Config.h>
    #include <SFML/Audio.h>
    #include <stddef.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080
    #define MAX_FRAMERATE 60
    #define TEXTURES_NB 3
    #define TEXTS_NB 2
    #define MAX_DEPTH_WIDTH 30//30 //Changeable (Maximum subdivision depth)
    #define SUBCHUNK_ROOT 2//3 //Changeable (Setting to more than 5 is mean)
    #define PLANES_MAX 9 //Changeable (Number of planes needed to subdivide)
    #define SUBROOT_LIMIT 7 //Changeable (Please don't abuse)
    #define DO_PRECISION true //Changeable (Slightly slows but is smoother)
    #define DO_PLANES_COLLIDE true //Changeable
    #define DO_TOWER_CROSSSIDES true //Changeable
    #define DRAW_EMPTY_CHUNKS false //Changeable
    #define COVER_BEFORE false //Changeable (Is experimental, Mess with colors)
    #define FAST_TOWER_DEPTH 1 // Changeable (Depth where planes are covered)
    #define PLANE_HEIGHT 20
    #define PLANE_WIDTH 20
    #define TOWER_HEIGHT 0.7
    #define TOWER_WIDTH 0.7

typedef enum state_s {
    WAITING = 0,
    RESTING,
    FLYING,
    DEAD
} state_t;

typedef enum environment_s {
    UNCOVERED = 0,
    SAFE
} env_t;

typedef struct my_texture {
    char *name;
    sfTexture *texture;
} my_texture_t;

typedef struct my_text {
    char *name;
    sfText *text;
    sfVector2f pos;
    int csize;
} my_text_t;

typedef struct mytower {
    sfRectangleShape *rectangle;
    sfCircleShape *circle;
    sfVector2f pos;
    float radius;
} tower_t;

typedef struct myplane {
    env_t environment;
    sfVector2f direction;
    sfVector2f departure;
    sfVector2f pos;
    sfVector2f arrival;
    float speed_pps;
    float departure_delay;
    sfRectangleShape *textbox;
    sfRectangleShape *hitbox;
    state_t state;
    float rotation;
} plane_t;

typedef struct chunk_s {
    sfVector2f pos;
    sfVector2f size;
    struct chunk_s **subchunks;
    plane_t **planes;
    tower_t **towers;
    sfRectangleShape *rect;
    int amount_crafts;
    int amount_towers;
    char depth;
} chunk_t;

typedef struct structures_s {
    llist_t *towers;
    llist_t *planes;
} structures_t;

typedef struct game_instance_s {
    float seconds;
    sfRenderWindow *win;
    sfRectangleShape *background;
    bool show_divides;
    bool entities_shown;
    bool hitboxes_shown;
    char max_depth;
    char max_planes;
    char subroot;
    chunk_t *original_chunk;
    plane_t **planes;
    tower_t **towers;
    my_texture_t *textures;
    sfFont *font;
    my_text_t *texts;
} game_t;

game_t *new_game_instance(structures_t *towers_and_planes);
void destroy_game_instance(game_t *game);
my_texture_t *load_textures(void);
int get_script(structures_t *towers_and_planes, FILE *stream);
int n_are_posints(char **word_array, int n);
int my_strcmp(char *s1, char *s2);
tower_t *create_tower(char **structure);
plane_t *create_plane(char **structure);
int my_atoi(char const *str);
int ptrlen(char **array);
char **str_to_word_array(char *string, char delimiter);
int append_structure(structures_t *towers_and_planes, char *lineptr);
char *my_strndup(const char *src, int n);
void print_framerate(game_t *game);
void my_put_str(int fd, const char *str);
void my_put_nbr(int nb);
sfTexture *look_for_texture(my_texture_t *textures, char *name);
void show_hitboxes(game_t *game);
void divide_chunk(chunk_t *parent, char subroot);
chunk_t *create_original_chunk(plane_t **planes, tower_t **towers);
int empty_chunk(chunk_t *chunk);
int exit_error(char *str);
void structure_collisions(tower_t **towers, plane_t **planes);
bool collide_square_tower(sfVector2f square_pos,
    sfVector2f square_size, tower_t *tower);
void closest_to_chunk(float *val, float x, float w);
float distance(float x, float y);
void interact_hitboxes(game_t *game);
void interact_sprites_visibility(game_t *game);
void interact_divide_visibility(game_t *game, sfKeyEvent event);
my_text_t *load_texts(game_t *game);
void collide_plane_tower(plane_t *plane, sfVector2f plane_pos,
    sfVector2f plane_size, tower_t *tower);
void collide_with_planes(plane_t **planes, int i);
void closest_to_rect(float *val, float ref, float ref_rad);
void set_texture_planes(my_texture_t *textures, plane_t **planes);
void set_texture_towers(my_texture_t *textures, tower_t **towers);
void append_if_pcollide(chunk_t *chunk, plane_t *plane, llist_t **planes_list);
void append_if_tcollide(chunk_t *chunk, tower_t *tower, llist_t **towers_list);
void move_planes(game_t *game);
void draw_window(game_t *game);
int display_help(void);
void print_nofilepath(int ac);
void change_envs(tower_t **towers, plane_t **planes);
float my_atof(char const *str);
int is_posint(char *str);
int n_are_posfloats(char **word_array, int n);
void stop_fps(void);
#endif
