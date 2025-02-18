##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## What a relief
##

CC = gcc

CFLAGS = -Wextra -Wall -Werror -I./include/

DFLAGS = -ggdb -g3

LIB = -L./llists/ -lm -lcsfml-graphics -lcsfml-system -lllists

NAME	=	my_radar

SRC	=	main.c \
	new_game_instance.c \
	load_textures.c \
	load_texts.c \
	my_strcmp.c \
	get_script.c \
	append_structure.c \
	my_atoi.c \
	ptrlen.c \
	n_are_posints.c \
	str_to_word_array.c \
	my_strndup.c \
	print_framerate.c \
	my_put_str.c \
	my_put_nbr.c \
	look_for_texture.c \
	show_hitboxes.c \
	new_chunk.c \
	structure_collisions.c \
	interact_sprites_visibility.c \
	interact_divide_visibility.c \
	collides.c \
	distances.c \
	set_textures.c \
	chunk_collides.c \
	empty_chunk.c \
	create_tower.c \
	create_plane.c \
	args_error.c \
	draw_window.c \
	move_planes.c \
	n_are_posfloats.c \
	my_atof.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	make -C llists/
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

debug :
	make debug -C llists/
	$(CC) -o $(NAME) $(SRC) $(LIB) $(CFLAGS) $(DFLAGS)

all : $(NAME)

clean :
	make clean -C llists/
	rm -rf $(OBJ)
	rm -rf *~

fclean : clean
	make fclean -C llists/
	rm -rf $(NAME)

re : fclean all
