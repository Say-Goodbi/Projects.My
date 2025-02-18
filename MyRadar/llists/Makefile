##
## EPITECH PROJECT, 2024
## organized
## File description:
## Compiles better than me
##

CC = gcc

CFLAGS = -Wextra -Wall -Werror -I.

DFLAGS = -ggdb -g3

NAME =	libllists.a

SRC =	$(wildcard *.c)

OBJ =   $(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

debug : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)
	rm -rf *~

fclean : clean
	rm -rf $(NAME)

#libmy.a : all
#	ar rcs libmy.a $(OBJ)

#unit_tests: fclean libmy.a
#	gcc $(SRC) tests/test_organized.c -o unit_tests $(CFLAGS) -lcriterion

re : fclean all
