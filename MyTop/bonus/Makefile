##
## EPITECH PROJECT, 2024
## my_top
## File description:
## Compiles better than me
##

NAME =	my_top

SRC =	main.c \
	fill_tophead.c \
	tophead_to_str.c \
	new_tophead.c \
	my_getuptime.c \
	my_getloadavg.c \
	gettasks.c \
	jump_to.c \
	my_getcpus.c \
	my_getmem.c \
	my_getswap.c \
	my_getusers.c \
	new_win.c \
	new_infos.c \
	fill_processes.c \
	get_process.c \
	cpucmp.c \
	sorted_insert.c \
	wprint_processes.c \
	destroy_list.c \
	getcomm.c \
	args_parse.c \
	kill_a_proc.c

$(NAME) :
	gcc -o $(NAME) $(SRC) -Wextra -Wall -Werror -lcurses

all : $(NAME)

clean :
	rm -rf *.o
	rm -rf *~

fclean : clean
	rm -rf $(NAME)

re : fclean all

debug :
	gcc -o $(NAME) $(SRC) -ggdb -lcurses
