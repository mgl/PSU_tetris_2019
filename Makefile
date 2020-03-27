##
## EPITECH PROJECT, 2019
## tetris
## File description:
## Makefile
##

NAME		=	tetris

SRC	=	src/tetrimino/file/open_dir.c		\
		src/tetrimino/file/sort_array.c 	\
		src/tetrimino/tetrimino.c 			\
		src/tetrimino/tetrimino_debug.c 	\
		src/tetrimino/file/read_tetrimino.c \
		src/tetrimino/array_utils.c		\
		src/tetris.c					\
		src/init_tetris.c				\
		src/get_arg.c					\
		src/set_tetris.c				\
		src/set_keys.c					\
		src/check_conflic.c				\
		src/debug_arg.c					\
		src/game/game.c					\

test_NAME	=	unit_test

MAIN 		=	src/main.c

test_SRC	=	$(SRC)							\
				tests/test_init_tetris.c		\
				tests/test_set_level.c			\
				tests/test_set_size.c			\
				tests/test_set_next.c			\
				tests/test_set_debug.c			\
				tests/test_get_arg.c			\
				tests/test_set_keys.c			\
				tests/test_compare.c			\
				tests/test_ckeck_conflict_keys.c\

OBJ			=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

test_OBJ	=	$(test_SRC:%.c=%.o)

INCLUDE		=	-I include

CFLAGS		=	-O2 -W -Wall -Wshadow -Wextra $(INCLUDE) -g

LIB_DIR		=	lib/my

LIB			=	-L $(LIB_DIR) -lmy -lncurses -lmenu

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
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				$(RM) -f $(test_OBJ)
				$(MAKE) clean
				./unit_test
				$(RM) -f $(test_NAME)
				$(RM) *.gcda
				$(RM) *.gcno

coverage:		$(test_OBJ)
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				$(RM) -f $(test_OBJ)
				$(MAKE) clean
				./unit_test
				gcovr -e tests/
				$(RM) -f $(test_NAME)
				$(RM) *.gcda
				$(RM) *.gcno

branch	:		$(test_OBJ)
				$(CC) -o $(test_NAME) $(test_SRC) $(test_LDFLAGS) $(CFLAGS)
				$(RM) -f $(test_OBJ)
				$(MAKE) clean
				./unit_test
				gcovr -e tests/ --branch
				$(RM) -f $(test_NAME)
				$(RM) *.gcda
				$(RM) *.gcno

.PHONY: all clean fclean re