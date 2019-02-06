.PHONY: all, clean, fclean, re

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = FdF
LDFLAGS = -Llibft
LDLIBS = -lft
LIB_DIR = libft
MINILIBX = minilibx
SRC = ./src/
INCLUDE = ./include/fdf.h

SRC_NAME =	$(SRC)bresenham_algo.c\
			$(SRC)color.c\
			$(SRC)draw.c\
			$(SRC)init.c\
			$(SRC)parsing.c\
			$(SRC)lst.c\
			$(SRC)transformation.c \
			$(SRC)inputs.c\
			$(SRC)main.c 

OBJ = $(SRC_NAME:.c=.o)

$(NAME): $(OBJ)
	cd $(LIB_DIR) && make
	cd $(MINILIBX) && make
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -I $(INCLUDE) -o $@ minilibx/libmlx.a -lmlx -lm  -framework OpenGL -framework AppKit
	
all : $(NAME)

clean :
		/bin/rm -f $(OBJ)
		cd $(LIB_DIR) && make $@
		cd $(MINILIBX) && make $@

fclean : clean
		/bin/rm -f $(NAME)
		/bin/rm -f libft/libft.a
		/bin/rm -f minilibx/libmlx.a

re : fclean all
	cd $(LIB_DIR) && make
	cd $(MINILIBX) && make