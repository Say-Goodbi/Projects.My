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
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *~

fclean : clean
	rm -rf unit_tests
	rm -rf $(NAME)

unit_tests: fclean
	gcc $(SRC) tests/*.c -o unit_tests --coverage -lcriterion

tests_run: unit_tests
	./unit_tests

test_result: tests_run
	gcovr --exclude tests
	gcovr --exclude tests --branches

re : fclean all
