##
## EPITECH PROJECT, 2019
## tetris
## File description:
## Makefile
##

NAME	=	tetris

SRC	=	src/main.c		\
		src/tetris.c	\
		src/tetrimino/tetrimino.c \
		src/tetrimino/tetrimino_debug.c \

OBJ	=	$(SRC:%.c=%.o)

INCLUDE	=	-I include

CFLAGS	=	-W -Wall -Wshadow -Wextra $(INCLUDE)

LIB_DIR	=	lib/my

LIB	=	-L $(LIB_DIR) -lmy

LDFLAGS	=	$(LIB)

CC	=	gcc

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

.PHONY: all clean fclean re