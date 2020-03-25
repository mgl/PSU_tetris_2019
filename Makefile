##
## EPITECH PROJECT, 2019
## tetris
## File description:
## Makefile
##

NAME		=	tetris

SRC	=	src/main.c						\
		src/tetris.c					\
		src/tetrimino/tetrimino.c 		\
		src/tetrimino/tetrimino_debug.c \
		src/init_tetris.c 				\

test_NAME	=	unit_test

MAIN 		=	src/main.c

SRC			=	src/tetris.c		\
				src/init_tetris.c	\
				src/get_arg.c		\
				src/set_tetris.c	\

test_SRC	=	$(SRC)					\
				tests/test_init_tetris.c\
				tests/test_set_level.c	\
				tests/test_set_size.c	\

OBJ			=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

test_OBJ	=	$(test_SRC:%.c=%.o)

INCLUDE		=	-I include

CFLAGS		=	-W -Wall -Wshadow -Wextra $(INCLUDE) -g

LIB_DIR		=	lib/my

LIB			=	-L $(LIB_DIR) -lmy

LDFLAGS		=	$(LIB)

test_LDFLAGS= 	-lcriterion --coverage $(LIB)

CC			=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
			$(MAKE) -C $(LIB_DIR)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(MAKE) -C $(LIB_DIR) clean
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) -C $(LIB_DIR) fclean
			$(RM) $(NAME)

re:	fclean all

tests_run:		$(test_OBJ)
				$(MAKE) -C $(LIB_DIR)
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				$(RM) -f $(test_OBJ)
				$(MAKE) clean
				./unit_test
				$(RM) -f $(test_NAME)
				$(RM) *.gcda
				$(RM) *.gcno

coverage:		$(test_OBJ)
				$(MAKE) -C $(LIB_DIR)
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				$(RM) -f $(test_OBJ)
				$(MAKE) clean
				./unit_test
				gcovr -e tests/ -e src/display.c
				$(RM) -f $(test_NAME)
				$(RM) *.gcda
				$(RM) *.gcno

branch	:		$(test_OBJ)
				$(MAKE) -C $(LIB_DIR)
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				$(RM) -f $(test_OBJ)
				$(MAKE) clean
				./unit_test
				gcovr -e tests/ -e src/display.c --branch
				$(RM) -f $(test_NAME)
				$(RM) *.gcda
				$(RM) *.gcno

.PHONY: all clean fclean re