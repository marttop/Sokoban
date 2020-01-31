##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_sokoban

SRC	=	src/main.c \
		src/get_file.c \
		src/move.c \
		src/my_strlen.c \
		src/get_nb_lines.c \
		src/get_nb_x.c \
		src/move_left.c \
		src/move_up.c \
		src/move_down.c \
		src/move_right.c \
		src/message.c \
		src/init_node.c \
		src/move_box.c \
		src/conditions.c \

SRC_TEST	=	src/get_file.c \
		src/move.c \
		src/my_strlen.c \
		src/get_nb_lines.c \
		src/get_nb_x.c \
		src/move_left.c \
		src/move_up.c \
		src/move_down.c \
		src/move_right.c \
		src/message.c \
		src/init_node.c \
		src/move_box.c \
		src/conditions.c \
		tests/unit_test.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-lncurses
CFLAGS	+=	-I./include -g3
FFLAGS = -L/usr/local/lib -lcriterion --coverage
FFLAGS += -fprofile-arcs -ftest-coverage

all	:	$(NAME)

tests_run :
	gcc -o test_run -O0 $(CFLAGS) $(FFLAGS) $(SRC_TEST)
	./test_run
coverage :
	/home/mszuts/.local/bin/gcovr --branch --exclude tests/
$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *gcda *gcno test_run

re	:	fclean all
